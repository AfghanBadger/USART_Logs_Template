#include <avr/interrupt.h>
#include <inttypes.h>



//USART init parameters ---------------
#define FOSC 16000000 // clock speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
//-------------------------------------

//asynchronous, interrupt driven with cyclic buffer-------
#define UART_RX_BUF_SIZE 50 //RX buffer size
#define UART_TX_BUF_SIZE 50


class CModuleUSART
{
    public:

    volatile char UART_RxBuf[UART_RX_BUF_SIZE];
    volatile char UART_TxBuf[UART_TX_BUF_SIZE];
    volatile uint8_t UART_TxHead;
    volatile uint8_t UART_TxTail;
    volatile uint8_t UART_RxHead;
    volatile uint8_t UART_RxTail;

    CModuleUSART();
    ~CModuleUSART();

    void Init(uint16_t uUbrr);

    void Send(uint8_t *pMsg);
    void Send(const char *pMsg);

};

extern CModuleUSART USART;