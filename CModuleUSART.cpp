#include "CModuleUSART.h"

//global
CModuleUSART USART;

CModuleUSART::CModuleUSART()
{
    this->UART_TxHead = 0;
    this->UART_TxTail = 0;
    this->UART_RxHead = 0;
    this->UART_RxTail = 0;
}
    
CModuleUSART::~CModuleUSART()
{

}

void CModuleUSART::Init(uint16_t uUbrr)
{

    //normal asynchronous mode
    UCSRA &=~ (1<<U2X);

    //set baud rate
    UBRRH = (unsigned char)((uUbrr >>8) & 0xFF);
    UBRRL = (unsigned char)(uUbrr & 0xFF);

    //enable Rx Tx and Rx interrupts
    UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<UDRIE);//(1<<TXCIE);//(1<<UDRIE); //| enable rx and tx interrupts

    //set frame format ( 8 data, 1 stop )
    UCSRC = (1<<URSEL)|(3<<UCSZ0);

}

void CModuleUSART::Send(uint8_t *pMsg)
{

}

void CModuleUSART::Send(const char *pMsg)
{
    uint8_t uLen = 0;
    while (pMsg[uLen] != '\0')
    {
        this->UART_TxBuf[uLen] = pMsg[uLen];
        uLen++;
    }
    this->UART_TxHead = uLen;
    UCSRB |= (1 << UDRIE);
}