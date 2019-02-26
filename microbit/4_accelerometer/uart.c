#include "gpio.h"
#include "uart.h"

void uart_init(){
  //Sets RXD pin to input
  GPIO->PIN_CNF[25]=0;
  //Sets TXD pin to output
  GPIO->PIN_CNF[24]=1;

  UART->PSELRTS=~0;
  UART->PSELCTS=~0;
  UART->PSELRXD=25;
  UART->PSELTXD=24;
  UART->BAUDRATE=0x00275000;
  UART->ENABLE=4;
  UART->STARTRX=1;

}

void uart_send(char letter){
  UART->STARTTX=1;
  UART->TXD=letter;
  while (!(UART->TXDREADY));
  UART->TXDREADY=0;
  UART->STOPTX=1;
}

char uart_read(){
  if (UART->RXDREADY){
    UART->RXDREADY=0;
    return UART->RXD;
  }
  return '\0';
}

void uart_send_str(char ** str){
  UART->STARTTX = 1;
  char * letter_ptr = *str;
  while(*letter_ptr != '\0'){
    UART->TXD = *letter_ptr;
    while(!UART->TXDREADY);
    UART->TXDREADY = 0;
    letter_ptr++;
  }
}
