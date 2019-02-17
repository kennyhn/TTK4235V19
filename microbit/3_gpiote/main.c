#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){
  // Configure LED Matrix
	for(int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
  init_GPIOTE();
  init_PPI();

  while(1);
  return 0;
}
