#include <avr/interrupt.h>
#include "CModuleUSART.h"

//____________________
// USART interrupts
ISR(USART_RXC_vect){

    char* charon;
    *charon = UDR;

    if((*charon > 31) & (*charon < 127) & USART.UART_RxHead < UART_RX_BUF_SIZE){
        USART.UART_RxBuf[USART.UART_RxHead] = *charon;
        USART.UART_RxHead++;
        
    }
}
//---------------------------------------------------------

ISR(USART_UDRE_vect){
    if(USART.UART_TxTail < USART.UART_TxHead){// until head meets the tail
        
        UDR = USART.UART_TxBuf[USART.UART_TxTail];// send tail
        USART.UART_TxTail++;// tail gets closer to head
    }
    else{//tail got bitten
        UCSRB &= ~(1<<UDRIE);// disable transmit
        for(int i = 0; i < USART.UART_TxHead; i++){//for the length of buffer
            USART.UART_TxBuf[i] = 0; // message transmitted, cleaning buffer
        }
        USART.UART_TxHead = 0;// back to zero
        USART.UART_TxTail = 0;// back to zero
    }
}