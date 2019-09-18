#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H_
//Implements an event queue.
//This event queue will be used by buttons_and_timers.c in order to add events to the queue
//And by main program in order to retrieve events

//Event queue configuration:
//How many events can event queue hold?
#define MAX_EVENTS  20
//How many events can priority event queue hold?
#define MAX_PRIORITY_EVENTS 20

//Note that if event queue is full and a new event is registered,
//event will be ignored, and FULL_EVENT_QUEUE will be returned
#define FULL_EVENT_QUEUE  0
#define SUCCESS 1

//Event struct. Events just have id and data.
typedef struct
{
        unsigned char id;        //Holds event identification
        unsigned char data;      //Event data
}EVENT_T;

//How many events are there in the queue?
int get_total_events_in_queue(void);

//Register new event
int register_event_in_queue(const EVENT_T *ev);

//Register new priority event
int register_event_in_priority_queue(const EVENT_T *ev);

//Return next event in event queue, or wait for one if event queue is empty.
void wait_for_event(EVENT_T* ev);

//Flush event queue
void flush_event_queue(void);  

//Note: priority events are always delivered before any pending normal event
#endif //EVENT_QUEUE_H_