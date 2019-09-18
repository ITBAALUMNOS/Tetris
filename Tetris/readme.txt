BACK END DOCUMENTATION:

*LED DISPLAY is connected VIA SPI
Connect LOAD to PORTA0
Connect CLK to SCK0
Connect DATA to MOSI0

*BUTTONS
Connect all buttons to PORTB
PORTB0 ->BUTTON UP          (1 in pulldowns)
PORTB1 ->BUTTON DOWN        (2 in pulldowns)
PORTB2 ->BUTTON LEFT        (3 in pulldowns)
PORTB3 ->BUTTON RIGHT       (4 in pulldowns)
PORTB4 ->BUTTON UP_LEFT     (5 in pulldowns)
PORTB5 ->BUTTON UP_RIGHT    (6 in pulldowns)
PORTB6 ->BUTTON DOWN_LEFT   (7 in pulldowns)
PORTB7 ->BUTTON DOWN_RIGHT  (8 in pulldowns)

*LEDDisplay
connect DIN to OC6 pin

Documentation to be improved... :)
