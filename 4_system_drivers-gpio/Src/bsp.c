#include "bsp.h"
#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)

#define PIN5		(1u<<5)
#define LED_PIN		PIN5
#define PIN13		(1U<<13)
#define BTN_PIN		PIN13

void led_init(void){
	RCC->AHB1ENR |= GPIOAEN; //Enable clock access to GPIOA
	GPIOA->MODER |= (1U<<0); //Set PA5 mode to output mode
	GPIOA->MODER &=~(1U<<11);
}

void led_on(void){
	GPIOA->ODR |= LED_PIN;  //Set PA5 high
}

void led_off(void){
	GPIOA->ODR &= ~LED_PIN;  //Set PA5 LOW
}

void button_init(void){
	RCC->AHB1ENR |= GPIOCEN; //Enable clock access to PORTC
	GPIOC->MODER &= ~(1u<<26); //Set PC13 as an input pin
	GPIOC->MODER &= ~(1u<<27);
}

bool get_btn_state(void){
	//note BTN is active low
	if(GPIOC->IDR & BTN_PIN){ // Check if button is pressed
		return false;
	}else{
		return true;
	}
}

