
/* ___   __      _                  ______           _                 
 / _ \ / _|    | |                 | ___ \         | |                
/ /_\ \ |_ __ _| |__   __ _ _ __   | |_/ / __ _  __| | __ _  ___ _ __ 
|  _  |  _/ _` | '_ \ / _` | '_ \  | ___ \/ _` |/ _` |/ _` |/ _ \ '__|
| | | | || (_| | | | | (_| | | | | | |_/ / (_| | (_| | (_| |  __/ |   
\_| |_/_| \__, |_| |_|\__,_|_| |_| \____/ \__,_|\__,_|\__, |\___|_|   
           __/ |               ______                  __/ |          
          |___/               |______|                |___/           */


// ATmega8A flash = 8 KB
//  EEPROM = 512 B
//  SRAM = 1 KB

// size = 564B



// Libraries ------------------
#include <avr/io.h>
#include <avr/delay.h>
#include "Interrupts.h"


// Frankfurt
//~~~~~~~~~~~~~~~~~~~~~~~~~
int main(void){

    // S E T U P     
    USART.Init(MYUBRR);
    sei();

    //USART.TestSend();
    USART.Send("\nWhiskey Logs");
    DDRC |= (1 << PC4);
    PORTC |= (1 << PC4);

    DDRC &= ~(1 << PC3);
    PORTC |= (1 <<PC3);

    // L O O P
    //main program loop-----------------------------------------------------
    while(1){

	    if(PINC & (1 << PC3)){
		    _delay_ms(50);
		    while(PINC & (1 << PC3));
		    PORTC ^= (1 << PC4);
	    }
        
	// main loop content :v
    }
}


