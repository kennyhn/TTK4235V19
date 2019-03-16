#include "gpiote.h"

void init_GPIOTE(){
  //Setting pin 0 to event
  GPIOTE->CONFIG[0]= 1 | (17<<8) | (2<<16);
  //Setting pins to task
  for (int i=1; i<4; i++){
    GPIOTE->CONFIG[i]=3 | ((12+i)<<8) | (3<<16);
  }
}
