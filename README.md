# SK-S7G2-Examples
This is a collection of Renesas' S7G2 Starter Kit code examples. They were built on SSP 1.6 and e2Studio 

## BlinkyButton
This is a simple blinky application, modeled as a state machine. The board button controls the direction of the triple LED blink.

## Interrupt
This is another blinky application, indicating how and where to setup interrupt callbacks.

## Timer
Yes, another blinky application, this time using a timer to produce the delay between led states.

## UART
Finally a non-blinky application. This example uses a UART module to print a single phrase over a UART TX pin. Note that this implementation does not work for USB virual COM port. To display the printed prhase, you need to use either a UART analyzer direct plugged to the UART_TX pin, or to use a FTDI to create a virtual COM port.
