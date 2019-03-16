#include "twi.h"
#include "gpio.h"
#include "gpiote.h"
#include <stdlib.h>


#define SCL_PIN 30
#define SDA_PIN 0

void twi_init(){
  //SCL pin, S0D1, input, pull up
  GPIO->PIN_CNF[SCL_PIN] = 0 | (3<<2) | (6<<8);
  //SDA pin, S0D1, input, pull up
  GPIO->PIN_CNF[SDA_PIN] = 0 | (3<<2) | (6<<8);

  TWI0->PSELSCL = 30; //Select pin number 30
  TWI0->PSELSDA = 0; //Select pin number 0

  //Sets frequency at 100 kbps
  TWI0->FREQUENCY = 0x01980000;


  TWI0->TXDSENT=0;
  TWI0->RXDREADY=0;
  //Enable TWI
  TWI0->ENABLE=5;

}


void twi_multi_read(uint8_t slave_address, uint8_t start_register, int registers_to_read, uint8_t* data_buffer){
  TWI0->ADDRESS=slave_address;

  //Start transmitting
  TWI0->STARTTX = 1;
  TWI0->TXDSENT = 0;
  TWI0->TXD=0;
  TWI0->TXD = start_register;
  //Wait for ACK
  while(!TWI0->TXDSENT);

  //Debugging purposes: Turns on the lights on the microbit
  for(int i = 13; i<=15; i++)
    GPIO->OUTSET=(1<<i);
  //Debugging purposes


  TWI0->STARTRX = 1;
  for (int i = 0; i<registers_to_read-1; i++){
    //Read from said register
    while(!TWI0->RXDREADY);
    TWI0->RXDREADY = 0;
    data_buffer[i] = TWI0->RXD;
  }

  TWI0->STOP = 1;
  data_buffer[registers_to_read-1] = TWI0->RXD;
  TWI0->RXDREADY = 0;
}


void twi_multi_write(uint8_t slave_address, uint8_t start_register, int registers_to_write, uint8_t* data_buffer){
  TWI0->ADDRESS=slave_address;

  //Start transmitting
  TWI0->TXDSENT = 0;
  TWI0->STARTTX = 1;
  TWI0->TXD = start_register;
  while(!TWI0->TXDSENT);

  TWI0->STARTTX=1;
  for (int i = 0; i<registers_to_write; i++){
    //Write to register
    TWI0->TXD=data_buffer[i];
    TWI0->TXDSENT=0;
    while(!TWI0->TXDSENT);
  }
  TWI0->STOP = 1;
}

uint8_t twi_test(){
  uint8_t* data_buffer;
  data_buffer = (uint8_t *) malloc(8*sizeof(uint8_t));
  twi_multi_read(0x1D, 0x0D, 2, data_buffer);
  uint8_t who_am_i = *data_buffer;
  free(data_buffer);
  return who_am_i;

}
