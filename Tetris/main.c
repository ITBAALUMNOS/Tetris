#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LEDdisplay.h"
#include "buttons_and_timers.h"

#include "display_spi_management.h"
#define GAME_END_ANI_SPEED	75	//MS
#define DROP_XCORD	((DISPLAY_WIDTH - PIECE_CONTAINER_SIZE)/2)
#define DROP_YCORD	1
#define NUM_BLINK_CLR_LINE 3

//Pieces enum
#define PIECE_CONTAINER_SIZE    4
#define TOTAL_PIECES 7  //Pieces from 1 to 7
typedef enum  { NO_PIECE = 0, PIECE_I, PIECE_J, PIECE_L, PIECE_O, PIECE_S, PIECE_T, PIECE_Z }  piece_type_t;   //Will take as int remember to CAST!!!!!!
#define TOTAL_ORIENTATIONS 4
typedef enum { RIGHT = 0, STRAIGHT, LEFT, UPSIDE_DOWN } rotation_t;     //Idem

typedef enum { PRE_START = 0, GAME_START, MAIN_MENU, NORMAL_PLAY, GAME_PAUSED, CLEARING_ROWS, GAME_FINISHED_ANIMATION } game_states_t;

//MUST HAVE SAME VALUES AS ENUM IN BUTTON AND TIMERS
enum BUTTONS { JOYSTICK_UP = 0, JOYSTICK_DOWN, JOYSTICK_LEFT, JOYSTICK_RIGHT, ROTATE_COUNT, ROTATE_CLOCK, PAUSE, RESET };
/*
*  A piece will have the following format it will be contained inside a "4 x 4 array" (represented with a 2 byte/16 bit unsigned int)
*
*   Msbit
*   ^
*  | _ _ _
*  |_|_|_|_|
*  |_|_|_|_|
*  |_|_|_|_|
*  |_|_|_|_--> Lsbit
*
* Where each bit represents if the square is in use or not
*	Examples:
*
*  I:
*   _ _ _ _
*  |_|*|_|_|   0100
*  |_|*|_|_|	0100	Whole int: 0100 0100 0100 0100 = 0x4444  BIG ENDIAN!!!
*  |_|*|_|_|	0100
*  |_|*|_|_|	0100
*
*   T:
*   _ _ _ _
*  |_|_|_|_|   0000
*  |_|_|*|_|	0100	Whole int: 0000 0100 0111 0000 = 0x0470  BIG ENDIAN!!!
*  |_|*|*|*|	0111
*  |_|_|_|_|	0000
*/

typedef unsigned int piece_shape_t; //16 bits
static const piece_shape_t tetris_pieces[1 + TOTAL_PIECES][TOTAL_ORIENTATIONS] =
{
	//NO_PIECE (Just to keep enum order)
	{ 0x0000,0x0000,0x0000,0x0000 },
	// PIECE_I
	{ 0x0F00,0x2222,0x00F0,0x4444 },
	// PIECE_J
	{ 0x8E00,0x6440,0x0E20,0x44C0 },
	// PIECE_L
	{ 0x2E00,0x4460,0x0E80,0xC440 },
	//PIECE_O
	{ 0x6600,0x6600,0x6600,0x6600 },
	// PIECE_S
	{ 0x6C00,0x4620,0x06C0,0x8C40 },
	// PIECE_T
	{ 0x4E00,0x4640,0x0E40,0x4C40 },
	// PIECE_Z
	{ 0xC600,0x2640,0x0C60,0x4C80 }
};
/*
const color piece_color[1 + TOTAL_PIECES] =
{
//{g,r,b}               //SAME ORDER AS piece_type_t enum

{ 0,		0,     		0 },  	//NO PIECE
{ 255,		0,      	0 },  	//PIECE_I
{ 0,		255,			0 },	//PIECE_J
{ 0,		0,			255 },	//PIECE_L
{ 255,		255,			255 },	//PIECE_O
{ 255,		0,      	255 },	//PIECE_S
{ 255,		255,			0 },	//PIECE_T
{ 0,		255,		255},	//PIECE_Z
};
};*/
const color piece_color[1 + TOTAL_PIECES] =
{
	//{g,r,b}               //SAME ORDER AS piece_type_t enum

	{ 0,		0,     		0 },  	//NO PIECE
	{ 16,		0,      	8 },  	//PIECE_I
	{ 0,		0,			16 },	//PIECE_J
	{ 8,		25,			0 },	//PIECE_L
	{ 16,		16,			0 },	//PIECE_O
	{ 16,		8,      	0 },	//PIECE_S
	{ 0,		8,			8 },	//PIECE_T
	{ 0,		16,		0 },	//PIECE_Z
};
typedef struct
{
	unsigned int fall_piece : 1;//If the piece is falling this is set to 1, used to distinguish placed pieces from the active one
	unsigned int redraw : 1;//Modified blocks will be set to 1, allowing for optimization when having to draw.

	unsigned int : 1;//Empty
	unsigned int : 1;//Empty
	unsigned int : 1;//Empty open for future use
	unsigned int piece_type : 3;//used to distinguish between piece type
}block_t;
#define HIDDEN_ROWS 4

#define SCORE_LEVEL_UP	200
#define NUMBER_SPEEDS	16
static unsigned int game_speed[NUMBER_SPEEDS] =
{
	200, 190, 180, 170, 160, 150, 140, 130, 120 , 110 , 100 , 90 , 80 , 70 , 60 , 50
};

static unsigned int score_per_line_cleared[] =
{
	0, 40, 100 , 200 , 400
};

static block_t logic_board_data[HIDDEN_ROWS + DISPLAY_HEIGHT][DISPLAY_WIDTH];
//Pointers to rows! In order to implement fast row erase



block_t(*board[HIDDEN_ROWS + DISPLAY_HEIGHT])[DISPLAY_WIDTH];

void init_row_pointers()
{
	int j;
	for (j = 0; j < DISPLAY_HEIGHT + HIDDEN_ROWS; j++)
		board[j] = &(logic_board_data[j]);
}


void seed_rand(void);    //Call this after initializing everything!
void clear_board_to_block(block_t block_to_clear);
void update_display_data(void);
void update_all_display_data(void);
unsigned char get_piece_data(signed int piece_x, unsigned int piece_y, piece_type_t piece_type, rotation_t rotation);
unsigned char can_place_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation);
void remove_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation);
void place_falling_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation);
void place_static_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation);

unsigned char move_piece_up(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation);
unsigned char move_piece_down(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation);
unsigned char move_piece_left(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation);
unsigned char move_piece_right(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation);
unsigned char rotate_piece_clockwise(signed char * x, signed char * y, piece_type_t *piece_type, rotation_t * rotation);
unsigned char rotate_piece_counterclockwise(signed char * x, signed char * y, piece_type_t *piece_type, rotation_t * rotation);
unsigned char check_cleared_rows(unsigned char y_cord);
void move_line_to_top(unsigned char line_row);
unsigned char is_game_over(void);

void manage_button_down(signed char * x, signed char * y, piece_type_t * piece, rotation_t * rotation, EVENT_T * ev, unsigned char *drop_piece_f, game_states_t * current_state);
unsigned char game_end_animation(signed char * y, piece_type_t last_piece_placed);
unsigned char clearing_row_animation(signed char y, unsigned char cleared_rows, unsigned long int * score);
void game_pause_animation(signed char x, unsigned char y, piece_type_t piece_type, rotation_t rotation);

void clear_line(unsigned char y_cord);
void move_line_up(unsigned char y_cord);
void place_piece_line(unsigned char y_cord, piece_type_t piece);
void set_row_redraw(unsigned char y_cord);

void draw_letter_t(piece_type_t piece, signed char y, signed char x);
void draw_letter_e(piece_type_t piece, signed char y, signed char x);
void draw_letter_r(piece_type_t piece, signed char y, signed char x);
void draw_letter_i(piece_type_t piece, signed char y, signed char x);
void draw_letter_s(piece_type_t piece, signed char y, signed char x);
//Note for allegro simulator:
//BUTTONS 0 to 7 are mapped from Q to I. You can change this in buttons_and_timers.c variable button_map!
int main(void)
{
	//REMEMBER VARIABLES BEFORE CODE!
	//Connect buttons to PORTB with pull-up resistors
	unsigned char redraw = 0, cleared_rows = 0, drop_piece_f = 0;
	unsigned int piece_fall_time = 50; //ms para que empiece rapido la animacion
	unsigned long int score = 0;
	signed char x, y;
	piece_type_t piece;
	rotation_t rotation;
	game_states_t current_state = PRE_START;
	block_t empty;
	//DO NOT FORGET THIS FUNCTION
	init_row_pointers();

	configure_spi_max7219_display();
	empty.fall_piece = 0;
	empty.redraw = 1;
	empty.piece_type = NO_PIECE;
	LEDdisplay_init();
	buttons_and_timers_init();
	set_timer_period_ms(TIMER_0, piece_fall_time);
	clear_board_to_block(empty);
	update_display_data();
	//This is to indicate that device is working and waiting for input to seed rand
	LEDdisplay_set_pixel(0, 0, LEDdisplay_map_rgb(255, 255, 255));
	LEDdisplay_set_pixel(DISPLAY_WIDTH - 1, 0, LEDdisplay_map_rgb(255, 255, 255));
	LEDdisplay_set_pixel(0, DISPLAY_HEIGHT - 1, LEDdisplay_map_rgb(255, 255, 255));
	LEDdisplay_set_pixel(DISPLAY_WIDTH - 1, DISPLAY_HEIGHT - 1, LEDdisplay_map_rgb(255, 255, 255));

	LEDdisplay_update();
	send_number_display(12345678);
	seed_rand();
	clear_board_to_block(empty);
	update_display_data();
	LEDdisplay_update();
	set_button_repeat_period_ms(100);
	flush_event_queue();
	for (;;)
	{
		EVENT_T ev;
		redraw = 0;
		configure_spi_max7219_display();
		send_number_display(score);
		wait_for_event(&ev);

		switch (current_state)
		{
		case PRE_START:
			score = 0;
			send_number_display(score);
			draw_letter_t(PIECE_I, HIDDEN_ROWS + 1, 1);
			draw_letter_e(PIECE_J, HIDDEN_ROWS + 6, 4);
			draw_letter_t(PIECE_L, HIDDEN_ROWS + 11, 1);
			draw_letter_r(PIECE_O, HIDDEN_ROWS + 16, 4);
			draw_letter_i(PIECE_S, HIDDEN_ROWS + 21, 1);
			draw_letter_s(PIECE_T, HIDDEN_ROWS + 26, 4);
			if (ev.id == BUTTON_PRESS)
				current_state = GAME_START;
			redraw = 1;
			break;
		case GAME_START:

			flush_event_queue();
			clear_board_to_block(empty);
			place_falling_piece(x = DROP_XCORD, y = DROP_YCORD, piece = (rand() % TOTAL_PIECES) + 1, rotation = rand() % TOTAL_ORIENTATIONS); //DESPUES CAMBIAR RESTO/MODULO
			update_display_data();
			LEDdisplay_update();
			current_state = NORMAL_PLAY;
			set_timer_period_ms(TIMER_0, piece_fall_time = game_speed[0]);//FALL TIME

			break;

		case NORMAL_PLAY:
			switch (ev.id)
			{
			case BUTTON_PRESS:
				if (!drop_piece_f) // If a piece is hard dropping, (joystick moved up) no other events button events are attended
				{
					manage_button_down(&x, &y, &piece, &rotation, &ev, &drop_piece_f, &current_state);
					redraw = 1;
				}
				break;

			case BUTTON_REPEAT: //Instead of detecting button repeat, it's send to priority queue as button press
				if (ev.data == JOYSTICK_UP || ev.data == JOYSTICK_DOWN || ev.data == JOYSTICK_LEFT || ev.data == JOYSTICK_RIGHT) //Only repeat the movement buttons no the rotating
				{
					ev.id = BUTTON_PRESS;
					register_event_in_priority_queue(&ev);
				}
				break;

			case TIMER:

				if (move_piece_down(x, y, piece, rotation))
				{
					y++;
					redraw = 1;
				}
				else
				{
					place_static_piece(x, y, piece, rotation);
					if (drop_piece_f)
					{
						drop_piece_f ^= 1; //sets to 0
						set_timer_period_ms(TIMER_0, piece_fall_time);//FALL TIME
						flush_event_queue();
					}
					cleared_rows = check_cleared_rows(y);
					if (cleared_rows)
					{
						set_timer_period_ms(TIMER_0, 200); //Clear screen time
						current_state = CLEARING_ROWS;//desactivar el redraw
					}
					else if (y <= 4 && is_game_over()) // no point in checking if y is over 4
						current_state = GAME_FINISHED_ANIMATION;
					else
					{
						place_falling_piece(x = DROP_XCORD, y = DROP_YCORD, piece = (rand() % TOTAL_PIECES) + 1, rotation = rand() % TOTAL_ORIENTATIONS);//cambiar por and dsp
						redraw = 1;
					}

				}
				break;

			default:
				break;
			}
			break;

		case CLEARING_ROWS:
			if (ev.id == TIMER)
			{
				if (clearing_row_animation(y, cleared_rows, &score))//If clear row animation finished
				{
					if (is_game_over())//might still be game over after clearing
						current_state = GAME_FINISHED_ANIMATION;
					else
					{
						place_falling_piece(x = DROP_XCORD, y = DROP_YCORD, piece = (rand() % TOTAL_PIECES) + 1, rotation = rand() % TOTAL_ORIENTATIONS);//cambiar por and dsp
						current_state = NORMAL_PLAY;
						piece_fall_time = ((score / SCORE_LEVEL_UP) < NUMBER_SPEEDS) ? game_speed[score / SCORE_LEVEL_UP] : game_speed[NUMBER_SPEEDS - 1];
						set_timer_period_ms(TIMER_0, piece_fall_time);//FALL TIME
						send_number_display(score);
						update_all_display_data();
					}
				}
				redraw = 1;
			}
			break;

		case GAME_PAUSED:
			if (ev.id == TIMER)
			{
				set_timer_period_ms(TIMER_0, 400);
				game_pause_animation(x, y, piece, rotation);
				redraw = 1;
			}
			else if (ev.id == BUTTON_PRESS && ev.data == BUTTON_6) //Resumes games
			{
				set_timer_period_ms(TIMER_0, piece_fall_time);
				place_falling_piece(x, y, piece, rotation);
				update_all_display_data();
				current_state = NORMAL_PLAY; //RESUME_GAME
			}
			else if (ev.id == BUTTON_PRESS && ev.data == BUTTON_7) // Reset game
			{
				place_falling_piece(x, y, piece, rotation);
				current_state = GAME_FINISHED_ANIMATION;

			}
			break;


		case GAME_FINISHED_ANIMATION:
			if (ev.id == TIMER)
			{
				if (game_end_animation(&y, piece))
				{
					set_timer_period_ms(TIMER_0, 50);//So that the animation happens faster
					current_state = PRE_START;
				}
				redraw = 1;
			}
			break;


		case MAIN_MENU:

			break;
		}


		if (redraw && !get_total_events_in_queue())  //This is important.
		{
			update_display_data();
			//Each interrupt takes place every 50ms
			//Each display update takes about 20 ~ 25 ms
			//So let's make sure that if display needs to be updated
			//update only happens once every 50ms period.
			//So, there are about 25ms left for other things!
			//We want to have some spare time, just waiting for new events,
			//so that next interrupt arrives when display is not being updated.
			//else, interrupt will be postponed (interrupts are disabled while sending data),
			//and so will events!
			LEDdisplay_update();
			redraw = 0;
		}
	}
	for (;;);

	return 0; //Do not reach this line!
}

void game_pause_animation(signed char x, unsigned char y, piece_type_t piece_type, rotation_t rotation)
{
	static unsigned char count = 0;
	if (count & 0x01) //If it's an odd number
		remove_piece(x, y, piece_type, rotation);
	else
		place_falling_piece(x, y, piece_type, rotation);
	count++;
}
/*
* This function uses the clock of the microprocessor to seed the rand function
*	Receives and returns void/nothing
*
*/

void seed_rand(void)    //Call this after initializing everything!
{
	EVENT_T ev;
	unsigned int i = 0;
	bool stop = false;
	while(!stop)
	{
		i++;
		if(get_total_events_in_queue() != 0)
		{
			wait_for_event(&ev);
			if(ev.id == BUTTON_PRESS)
				stop = true;
		}
	}
	srand(i);
}

/*
* Clears the whole to board game to a selected block_t
*  Receive value:
*   -block_to_clear : The block which will be set in the whole board
*/
void clear_board_to_block(block_t block_to_clear)
{
	int x, y;
	block_to_clear.redraw = 1;
	for (y = 0; y < DISPLAY_HEIGHT + HIDDEN_ROWS; y++)
		for (x = 0; x < DISPLAY_WIDTH + HIDDEN_ROWS; x++)
			(*board[y])[x] = block_to_clear;
}

/*
* Update the whole Leddisplay matrix(which stores the corresponding values in rgb)
* only those blocks which have the redraw flag set.
*	 Receives and returns void/nothing
*/
void update_display_data(void)
{
	unsigned char x, y;
	for (y = 0; y < DISPLAY_HEIGHT; y++)
		for (x = 0; x < DISPLAY_WIDTH; x++)
			if ((*board[HIDDEN_ROWS + y])[x].redraw)
			{
				//LEDdisplay_set_pixel(x, y, piece_color[(*board[y + HIDDEN_ROWS])[x].piece_type]);
				LEDdisplay_set_pixel(x, y, piece_color[(unsigned char)(*board[y + HIDDEN_ROWS])[x].piece_type]);
				(*board[y + HIDDEN_ROWS])[x].redraw = 0;
			}
}
/*
* Update the whole Leddisplay matrix(which stores the corresponding values in rgb)
* all blocks are reset even those with the redraw flag not set(value in 0).
*	 Receives and returns void/nothing
*/
void update_all_display_data(void)
{
	unsigned char x, y;
	for (y = 0; y < DISPLAY_HEIGHT; y++)
		for (x = 0; x < DISPLAY_WIDTH; x++)
			(*board[y + HIDDEN_ROWS])[x].redraw = 1;

	update_display_data();
}

const unsigned int reverse_bit_flag[] =  //For optimization, faster than shifts
{
	0x8000,0x4000,0x2000,0x1000,0x0800,0x0400,0x0200,0x0100,0x0080,0x0040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001
};

/*
* This function receives cords INSIDE THE PIECE_CONTAINER_SIZE (4x4) and returns 1 if the cord has a block piece in it
*	Receive_value:
*		piece_x: x_cord of the tetris piece [0,3]
*		piece_y: y_cord of the tetris piece [0,3]
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool, 1 if the cord has a piece block. 0 if empty piece.
*/
unsigned char get_piece_data(signed int piece_x, unsigned int piece_y, piece_type_t piece_type, rotation_t rotation)
{
	if (piece_x >= PIECE_CONTAINER_SIZE || piece_y >= PIECE_CONTAINER_SIZE || piece_type > TOTAL_PIECES || rotation >= TOTAL_ORIENTATIONS)
		return 0;
	return (tetris_pieces[piece_type][rotation] & reverse_bit_flag[(4 * (piece_y)) + piece_x]) ? 1 : 0;
}

/*
* This function tells you if a piece can be placed at certain cordinates.
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is trying to be placed.
*		piece_y: x_cord of the board where the tetris piece is trying to be placed.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool: 1 if the piece can be placed 0 if it can not be placed.
*/
unsigned char can_place_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation)
{
	int piece_x, piece_y;
	for (piece_y = 0; piece_y < PIECE_CONTAINER_SIZE; piece_y++)
		for (piece_x = 0; piece_x < PIECE_CONTAINER_SIZE; piece_x++)
			if (
				get_piece_data(piece_x, piece_y, piece_type, rotation) &&
				(
					x + piece_x >= DISPLAY_WIDTH ||
					x + piece_x<0 ||
					y + piece_y >= DISPLAY_HEIGHT + HIDDEN_ROWS ||
					y + piece_y<0 ||
					(
					((*board[y + piece_y])[x + piece_x].piece_type != NO_PIECE) &&
						!(*board[y + piece_y])[x + piece_x].fall_piece
						)

					)
				)//If place is in use return false lazy || so no segfault
				return 0;
	return 1;
}
/*
* This function tells you if a piece can be removed at certain cordinates.
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is to be removed.
*		piece_y: x_cord of the board where the tetris piece is to be removed.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool: 1 if the piece can be placed 0 if it can not be placed.
*/
void remove_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation)
{
	int piece_x, piece_y;
	block_t empty;
	empty.redraw = 1; empty.fall_piece = 0; empty.piece_type = NO_PIECE;
	for (piece_y = 0; piece_y < 4; piece_y++)
		for (piece_x = 0; piece_x < 4; piece_x++)
			if (get_piece_data(piece_x, piece_y, piece_type, rotation))
				(*board[y + piece_y])[x + piece_x] = empty;

}
/*
* This function places an active piece at certain cords(falling piece flag 1). (ASSUMES THAT IT CAN BE PLACED CALL can_place_piece beforehand)
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be placed.
*		piece_y: x_cord of the board where the tetris piece is going to be placed.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		void
*/
void place_falling_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation)
{
	int piece_x, piece_y;
	block_t falling_piece;
	falling_piece.fall_piece = 1;
	falling_piece.redraw = 1;
	falling_piece.piece_type = piece_type;
	for (piece_y = 0; piece_y < 4; piece_y++)
		for (piece_x = 0; piece_x < 4; piece_x++)
			if (get_piece_data(piece_x, piece_y, piece_type, rotation))
				(*board[y + piece_y])[x + piece_x] = falling_piece;
}

/*
* Places a static piece at certain cords(falling piece flag 0). (ASSUMES THAT IT CAN BE PLACED CALL can_place_piece beforehand)
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be placed.
*		piece_y: x_cord of the board where the tetris piece is going to be placed.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		void
*/
void place_static_piece(signed int x, unsigned int y, piece_type_t piece_type, rotation_t rotation)
{
	unsigned char piece_x, piece_y;
	block_t static_piece;
	static_piece.redraw = 1;
	static_piece.fall_piece = 0;
	static_piece.piece_type = piece_type;
	for (piece_y = 0; piece_y < 4; piece_y++)
		for (piece_x = 0; piece_x < 4; piece_x++)
			if (get_piece_data(piece_x, piece_y, piece_type, rotation))
				(*board[y + piece_y])[x + piece_x] = static_piece;
}

/*
* JAJAJA NO ENTENDIA NADA CUANDO LA VI, DIJE CUANDO LA HICE YO :D -Rama -.-
*
*/
unsigned char move_piece_up(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation)
{
	//I make this functions just because I can! and for testing purposes
	if (can_place_piece(x, y - 1, piece_type, rotation))
	{
		remove_piece(x, y, piece_type, rotation);
		place_falling_piece(x, y - 1, piece_type, rotation);
		return 1;
	}
	else
		return 0;

}

/*
* This function moves an active piece at certain cords 1 row down(falling piece flag 1).
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be moved.
*		piece_y: x_cord of the board where the tetris piece is going to be moved.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool : True(1) if it can be moved down, false(0) if it cannot be placed.
*/
unsigned char move_piece_down(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation)
{
	if (can_place_piece(x, y + 1, piece_type, rotation))
	{
		remove_piece(x, y, piece_type, rotation);
		place_falling_piece(x, y + 1, piece_type, rotation);
		return 1;
	}
	else
		return 0;

}

/*
* This function moves an active piece at certain cords 1 column to the left (falling piece flag 1).
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be moved.
*		piece_y: x_cord of the board where the tetris piece is going to be moved.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool : True(1) if it can be moved left, false(0) if it cannot be placed.
*/
unsigned char move_piece_left(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation)
{
	if (can_place_piece(x - 1, y, piece_type, rotation))
	{
		remove_piece(x, y, piece_type, rotation);
		place_falling_piece(x - 1, y, piece_type, rotation);
		return 1;
	}
	else
		return 0;

}
/*
* This function moves an active piece at certain cords 1 column to the right (falling piece flag 1).
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be moved.
*		piece_y: x_cord of the board where the tetris piece is going to be moved.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool : True(1) if it can be moved right, false(0) if it cannot be placed.
*/
unsigned char move_piece_right(signed char x, signed char y, piece_type_t piece_type, rotation_t rotation)
{
	if (can_place_piece(x + 1, y, piece_type, rotation))
	{
		remove_piece(x, y, piece_type, rotation);
		place_falling_piece(x + 1, y, piece_type, rotation);
		return 1;
	}
	else
		return 0;

}
/*
* This function rotates an active piece(falling piece flag 1) at certain cords clockwise .
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be rotated.
*		piece_y: x_cord of the board where the tetris piece is going to be rotated.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool : True(1) if it can be rotated, false(0) if it cannot be rotated.
*
* THIS FUNCTION MODIFIES X, Y AND ROTATION
*/
unsigned char rotate_piece_clockwise(signed char * x, signed char * y, piece_type_t *piece_type, rotation_t * rotation)
{
	//TO_DO: IMPLEMENT COMPLEX ROTATION!
	if (can_place_piece(*x, *y, *piece_type, ((*rotation) + 1) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece(*x, *y, *piece_type, ((*rotation) + 1) & 0x03);
		(*rotation) = ((*rotation) + 1) & 0x03;
		return 1;
	}
	else if (*x < 0 && can_place_piece((*x) + 1, *y, *piece_type, ((*rotation) + 1) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) + 1, *y, *piece_type, ((*rotation) + 1) & 0x03);
		(*x)++;
		(*rotation) = ((*rotation) + 1) & 0x03;
		return 1;
	}
	else if (*x >(DISPLAY_WIDTH - PIECE_CONTAINER_SIZE) && can_place_piece((*x) - 1, *y, *piece_type, ((*rotation) + 1) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) - 1, *y, *piece_type, ((*rotation) + 1) & 0x03);
		(*x)--;
		(*rotation) = ((*rotation) + 1) & 0x03;
		return 1;
	}
	else if (*piece_type == PIECE_I && *x < -1 && can_place_piece((*x) + 2, *y, *piece_type, ((*rotation) + 1) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) + 2, *y, *piece_type, ((*rotation) + 1) & 0x03);
		(*x) += 2;
		(*rotation) = ((*rotation) + 1) & 0x03;
		return 1;

	}
	else if (*piece_type == PIECE_I && *x >(DISPLAY_WIDTH - 3) && can_place_piece((*x) - 2, *y, *piece_type, ((*rotation) + 1) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) - 2, *y, *piece_type, ((*rotation) + 1) & 0x03);
		(*x) -= 2;
		(*rotation) = ((*rotation) + 1) & 0x03;
		return 1;
	}
	else
		return 0;
}

/*
* This function rotates an active piece(falling piece flag 1) at certain cords COUNTERclockwise .
* Receive_value:
*		piece_x: x_cord of the board where the tetris piece is going to be rotated.
*		piece_y: x_cord of the board where the tetris piece is going to be rotated.
*		piece_type: Piece type I,L,S,Z,etc
*		rotation: The rotation of the piece (straight, upside_down, left,right)
* Return value:
*		bool : True(1) if it can be rotated, false(0) if it cannot be rotated.
*
* THIS FUNCTION MODIFIES X, Y AND ROTATION
*/
unsigned char rotate_piece_counterclockwise(signed char * x, signed char * y, piece_type_t *piece_type, rotation_t * rotation)
{
	//TO_DO: IMPLEMENT COMPLEX ROTATION!
	if (can_place_piece(*x, *y, *piece_type, ((*rotation) + 3) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece(*x, *y, *piece_type, ((*rotation) + 3) & 0x03);
		(*rotation) = ((*rotation) + 3) & 0x03;
		return 1;
	}
	else if (*x < 0 && can_place_piece((*x) + 1, *y, *piece_type, ((*rotation) + 3) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) + 1, *y, *piece_type, ((*rotation) + 3) & 0x03);
		(*x)++;
		(*rotation) = ((*rotation) + 3) & 0x03;
		return 1;
	}
	else if (*x >(DISPLAY_WIDTH - PIECE_CONTAINER_SIZE) && can_place_piece((*x) - 1, *y, *piece_type, ((*rotation) + 3) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) - 1, *y, *piece_type, ((*rotation) + 3) & 0x03);
		(*x)--;
		(*rotation) = ((*rotation) + 3) & 0x03;
		return 1;
	}
	else if (*piece_type == PIECE_I && *x < -1 && can_place_piece((*x) + 2, *y, *piece_type, ((*rotation) + 3) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) + 2, *y, *piece_type, ((*rotation) + 3) & 0x03);
		(*x) += 2;
		(*rotation) = ((*rotation) + 3) & 0x03;
		return 1;

	}
	else if (*piece_type == PIECE_I && *x >(DISPLAY_WIDTH - 3) && can_place_piece((*x) - 2, *y, *piece_type, ((*rotation) + 3) & 0x03))
	{
		remove_piece(*x, *y, *piece_type, *rotation);
		place_falling_piece((*x) - 2, *y, *piece_type, ((*rotation) + 3) & 0x03);
		(*x) -= 2;
		(*rotation) = ((*rotation) + 3) & 0x03;
		return 1;
	}
	else
		return 0;
}

/*
* This function checks the four lines after y_cord (including the line in y_cord)
* to see if the are complete. This is useful to know when a piece is placed which lines
* need to be deleted.
*  Receive value:
*		top y_cord: Line from which the following 4 inclusive will be checked
*  Return value examples:
*   - 0000 0001		Only first row to be cleared
*   - 0000 0011		First and second rows to be cleared
*   - 0000 1000		Only forth row to be cleared
*
*/
unsigned char check_cleared_rows(unsigned char y_cord)
{
	signed char x, y;
	unsigned char rows_to_clear = 0x00;
	char moving_mask = 0x01;
	char row_flag;
	//printf("Called with %d\n",y_cord);
	//sleep(1);
	for (y = y_cord; y < (DISPLAY_HEIGHT + HIDDEN_ROWS) && y < (y_cord + PIECE_CONTAINER_SIZE); y++, moving_mask <<= 1)
	{
		for (x = 0, row_flag = 1; x < DISPLAY_WIDTH; x++)
			if ((*board[y])[x].piece_type == NO_PIECE)
			{
				row_flag = 0;
				break;
			}
		if (row_flag)
			rows_to_clear |= moving_mask;

	}
	return rows_to_clear;

}


/*
* This function moves a line to the top of the array
* this includes the hidden rows so the row will be moved to the top hidden row.
*	Receive value:
*	 -line_row: the row in the array which will be move to the top row (first hidden row).
*/
void move_line_to_top(unsigned char line_row)
{
	block_t(*temp_line)[DISPLAY_WIDTH];
	for (; line_row > 0; --line_row)
	{
		temp_line = board[line_row];
		board[line_row] = board[line_row - 1];
		board[line_row - 1] = temp_line;
	}

}

/*
* This function checks if the tetris game is over
*	Receive:
*	 -void
*	Return:
*	 -bool (expressed as unsigned char because hc12 doesn't support bool): 1
*		1: game is over
*		0: game is not over
* The function checks 4 invisible line above playing rows if any block is present then the game is over
*
*/
unsigned char is_game_over(void)
{
	int i, j;
	for (i = 0; i < HIDDEN_ROWS; i++)
		for (j = 0; j < DISPLAY_WIDTH; j++)
			if ((*board[i])[j].piece_type != NO_PIECE)
				return 1;
	return 0;
}


/*
* This function manages the pressed buttones which are used to play, this are present in
* "button_and_timers.c"
* According to the button pressed one of the following functions  is called
*	-move_piece_down : moves the active tetris piece down if possible
*	-move_piece_up : moves the active tetris piece up if possible
*	-move_piece_right : moves the active tetris piece right if possible
*	-move_piece_left : moves the active tetris piece left if possible.
*	-rotate_piece_clockwise : rotates the piece clockwise/right if possible.
*	-rotate_piece_counterclockwise : rotates the piece counterclockwise/left if possible.
*/
void manage_button_down(signed char * x, signed char * y, piece_type_t * piece, rotation_t * rotation, EVENT_T * ev, unsigned char *drop_piece_f, game_states_t * current_state)
{
	switch (ev->data)//Possible buttons to press
	{
	case JOYSTICK_UP:
		*drop_piece_f = 1; //Me parece que conviene como un estado pq es muy cabeza como esta pero nose...
		set_timer_period_ms(TIMER_0, 50); //Lo mas rapido que se banca
		break;

	case JOYSTICK_LEFT:
		if (move_piece_left(*x, *y, *piece, *rotation))
			--(*x);
		break;

	case JOYSTICK_DOWN:
		if (move_piece_down(*x, *y, *piece, *rotation))
			++(*y);
		break;

	case JOYSTICK_RIGHT:
		if (move_piece_right(*x, *y, *piece, *rotation))
			++(*x);
		break;

	case ROTATE_COUNT:
		if (rotate_piece_counterclockwise(x, y, piece, rotation))
			;
		break;

	case ROTATE_CLOCK:
		if (rotate_piece_clockwise(x, y, piece, rotation))
			;
		break;

	case PAUSE: // Pause button
		if (*y >= 3)
			*current_state = GAME_PAUSED;
		break;

	default:
		break;
	}
}


unsigned char game_end_animation(signed char * y, piece_type_t last_piece_placed)
{
	static unsigned char first_call = 1;
	unsigned char animation_finished = 0; //bool
	if (first_call)
	{
		*y = DISPLAY_HEIGHT + HIDDEN_ROWS - 1;
		place_piece_line(*y, last_piece_placed);
		set_timer_period_ms(TIMER_0, GAME_END_ANI_SPEED);
		first_call = 0;
	}
	else
	{
		if (*y > 0)
		{
			clear_line((*y) - 1);
			move_line_up(*y);
			set_row_redraw((*y) - 1);
			--(*y);
		}
		else
		{
			first_call = 1;
			animation_finished = 1; // true
		}
	}
	return animation_finished;
}



void clear_line(unsigned char y_cord)
{
	block_t empty;
	int x;
	empty.fall_piece = 0;
	empty.redraw = 1;
	empty.piece_type = NO_PIECE;

	for (x = 0; x < DISPLAY_WIDTH; x++)
		(*board[y_cord])[x] = empty;
}

void move_line_up(unsigned char y_cord)
{
	block_t(*temp_line)[DISPLAY_WIDTH];
	temp_line = board[y_cord];
	board[y_cord] = board[y_cord - 1];
	board[y_cord - 1] = temp_line;
}

void place_piece_line(unsigned char y_cord, piece_type_t piece)
{
	int x;
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = piece;
	for (x = 0; x < DISPLAY_WIDTH; x++)
		(*board[y_cord])[x] = piece_block;
}

void set_row_redraw(unsigned char y_cord)
{
	int x;
	for (x = 0; x < DISPLAY_WIDTH; x++)
		(*board[y_cord])[x].redraw = 1;
}

unsigned char clearing_row_animation(signed char y, unsigned char cleared_rows, unsigned long int * score)
{
	static unsigned char number_blinks_clear = NUM_BLINK_CLR_LINE, lines_cleared = 0;

	unsigned char i, j, moving_mask, animation_finished = 0;
	block_t(*temp_line)[DISPLAY_WIDTH];
	block_t empty;
	empty.fall_piece = 0;
	empty.piece_type = NO_PIECE;
	empty.redraw = 1;
	if (number_blinks_clear-- > 0)
	{
		for (j = 0, moving_mask = 0x01; j < PIECE_CONTAINER_SIZE; j++, moving_mask <<= 1)
			if (cleared_rows & moving_mask)
			{
				temp_line = board[y + j];
				board[y + j] = board[j];
				board[j] = temp_line;
				for (i = 0; i <DISPLAY_WIDTH; i++)
					(*board[y + j])[i].redraw = 1;
				//(*board[j])[i].redraw = 1; // No se ve no tiene sentido redraw
			}
	}
	else
	{
		for (j = 0, moving_mask = 0x01; j < PIECE_CONTAINER_SIZE; j++, moving_mask <<= 1)
			if (cleared_rows & moving_mask)
				for (i = 0; i < DISPLAY_WIDTH; i++)
				{
					(*board[j])[i] = empty;
					(*board[y + j])[i] = empty;
				}
		//Soy tonto y no lo pude optimizar habria que verlo pero paja anda...
		for (j = 0, moving_mask = 0x01; j < 4; j++, moving_mask <<= 1)
			if (cleared_rows & moving_mask)
			{
				move_line_to_top(y + j);
				++lines_cleared;
			}

		*score += score_per_line_cleared[lines_cleared];
		animation_finished = 1;
		lines_cleared = 0, number_blinks_clear = NUM_BLINK_CLR_LINE;
	}
	return animation_finished;

}


void draw_letter_t(piece_type_t piece, signed char y, signed char x)
{
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = (unsigned int)piece;
	(*board[y])[x] = piece_block;
	(*board[y])[x + 1] = piece_block;
	(*board[y])[x + 2] = piece_block;
	(*board[y + 1])[x + 1] = piece_block;
	(*board[y + 2])[x + 1] = piece_block;
	(*board[y + 3])[x + 1] = piece_block;
	(*board[y + 4])[x + 1] = piece_block;

}

void draw_letter_e(piece_type_t piece, signed char y, signed char x)
{
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = piece;

	(*board[y])[x] = piece_block;
	(*board[y])[x + 1] = piece_block;
	(*board[y])[x + 2] = piece_block;

	(*board[y + 1])[x] = piece_block;
	(*board[y + 2])[x] = piece_block;
	(*board[y + 2])[x + 1] = piece_block;
	(*board[y + 2])[x + 2] = piece_block;

	(*board[y + 3])[x] = piece_block;
	(*board[y + 4])[x] = piece_block;
	(*board[y + 4])[x + 1] = piece_block;
	(*board[y + 4])[x + 2] = piece_block;
}

void draw_letter_r(piece_type_t piece, signed char y, signed char x)
{
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = piece;
	(*board[y])[x] = piece_block;
	(*board[y])[x + 1] = piece_block;
	(*board[y])[x + 2] = piece_block;

	(*board[y + 1])[x + 2] = piece_block;
	(*board[y + 2])[x + 2] = piece_block;
	(*board[y + 2])[x + 1] = piece_block;
	(*board[y + 3])[x + 1] = piece_block;
	(*board[y + 4])[x + 2] = piece_block;

	(*board[y + 1])[x] = piece_block;
	(*board[y + 2])[x] = piece_block;
	(*board[y + 3])[x] = piece_block;
	(*board[y + 4])[x] = piece_block;


}

void draw_letter_i(piece_type_t piece, signed char y, signed char x)
{
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = piece;
	(*board[y])[x] = piece_block;
	(*board[y])[x + 1] = piece_block;
	(*board[y])[x + 2] = piece_block;

	(*board[y + 1])[x + 1] = piece_block;
	(*board[y + 2])[x + 1] = piece_block;
	(*board[y + 3])[x + 1] = piece_block;

	(*board[y + 4])[x] = piece_block;
	(*board[y + 4])[x + 1] = piece_block;
	(*board[y + 4])[x + 2] = piece_block;
}

void draw_letter_s(piece_type_t piece, signed char y, signed char x)
{
	block_t piece_block;
	piece_block.fall_piece = 0;
	piece_block.redraw = 1;
	piece_block.piece_type = piece;
	(*board[y])[x] = piece_block;
	(*board[y])[x + 1] = piece_block;
	(*board[y])[x + 2] = piece_block;

	(*board[y + 1])[x] = piece_block;
	(*board[y + 2])[x] = piece_block;
	(*board[y + 2])[x + 1] = piece_block;
	(*board[y + 2])[x + 2] = piece_block;

	(*board[y + 3])[x + 2] = piece_block;
	(*board[y + 4])[x] = piece_block;
	(*board[y + 4])[x + 1] = piece_block;
	(*board[y + 4])[x + 2] = piece_block;
}
