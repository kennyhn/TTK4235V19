#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[120];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

int main(){
    // Configue LED matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

    while(1){
        // Turn LED matrix on
        GPIO->OUTSET = (1 << 13);
        GPIO->OUTSET = (1 << 14);
        GPIO->OUTSET = (1 << 15);

        // Turn LED matrix off
        GPIO->OUTCLR = (1 << 13);
        GPIO->OUTCLR = (1 << 14);
        GPIO->OUTCLR = (1 << 15);
    }

	return 0;
}
