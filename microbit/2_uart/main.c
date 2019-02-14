#include <stdio.h>
#include "gpio.h"
#include "uart.h"

int main(){
  uart_init();

  // Configure LED Matrix
  for(int i = 4; i <= 15; i++){
    GPIO->DIRSET = (1 << i);
    GPIO->OUTCLR = (1 << i);
  }

  // Configure buttons
  GPIO->PIN_CNF[17] = 0;
  GPIO->PIN_CNF[26] = 0;

  int sleep = 0;
  iprintf("Norway has %d counties.\n\r", 18);
  while(1){
    /* Check if button B is pressed;
     * send B if it is. */
     if (!((1<<26) & GPIO->IN)){
       uart_send('B');
     }
    /* Check if button A is pressed;
     * send A if it is. */
    if (!((1<<17) & GPIO->IN)){
      uart_send('A');
    }
    if (uart_read()){
      if ((GPIO->OUT)&(1 << 13)){
        for(int i = 13; i<=15; i++)
 				 GPIO->OUTCLR=(1<<i);

      }else{
        for(int i = 13; i<=15; i++)
  				GPIO->OUTSET=(1<<i);
      }
    }
    sleep = 10000;
    while(--sleep);
  }
  return 0;
}

ssize_t _write(int fd, const void *buf, size_t count){
  char * letter = (char *)(buf);
  for(int i = 0; i < count; i++){
    uart_send(*letter);
    letter++;
  }
  return count;
}
