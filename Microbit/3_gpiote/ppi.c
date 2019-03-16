#include "ppi.h"
#include "gpiote.h"

void init_PPI(){
  for (int i = 0; i<3; i++){
    PPI->PPI_CH[i].EEP = (uint32_t)&(GPIOTE->IN[0]);
    PPI->PPI_CH[i].TEP = (uint32_t) &(GPIOTE->OUT[i+1]);
    PPI->CHENSET = (1<<i);
  }
}
