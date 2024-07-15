#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
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
	debug_uart_init(); //initialize UART

	while(1){
		printf("hi there");
		for(int i=0;i<9000; i++){}
	}
}

