#include <stdio.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"
#include "adc.h"

/*Module
 * FPU
 * UART
 * GPIO
 * TIMEBASE
 * ADC
 */



bool btn_state;
uint32_t sensor_value;

int main(){

	fpu_enable(); //Enable FPU
	debug_uart_init(); //initialize UART
	timebase_init(); //init systick
	led_init(); // init led
	button_init(); // init button
	pa1_adc_init(); // init ADC
	start_conversion(); // start conversion

	while(1){
		printf("hi there");
		btn_state = get_btn_state();
		led_on();
		delay(1);
	}
}

