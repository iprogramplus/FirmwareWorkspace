#include "stm32f4xx.h"

#define GPIOAEN		(1u<<0)
#define PIN5		(1u<<5)
#define LED_PIN		PIN5

int main(){
	/* Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1u<<10);
	GPIOA->MODER &=~(1u<<11);

	while(1){
		GPIOA->ODR ^=LED_PIN;
		for(int i=0;i<100000;i++){}
	}
}
