#include "twi.h"
#include "uart.h"
#include "gpio.h"
#include "ubit_led_matrix.h"


int main(){
  twi_init();
  for(int i = 4; i <= 15; i++){
    GPIO->DIRSET = (1 << i);
    GPIO->OUTCLR = (1 << i);
  }

  uint8_t who_am_i = twi_test();
  for(int i = 13; i<=15; i++)
    GPIO->OUTSET=(1<<i);

  if (who_am_i == 0x5A){
    for(int i = 13; i<=15; i++)
      GPIO->OUTSET=(1<<i);
  }
  while(1);
  return 0;
}
