#include "stm32f4xx.h"
#include "fpu.h"

/*Module
 * FPU
 * UART
 * GPIO
 * TIMEBASE
 */

#define GPIOAEN		(1u<<0)
#define PIN5		(1u<<5)
#define LED_PIN		PIN5

int main(){
	fpu_enable(); //Enable FPU

	while(1){
	}
}

