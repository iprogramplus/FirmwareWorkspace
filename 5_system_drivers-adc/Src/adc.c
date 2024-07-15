#include "adc.h"

#define GPIOAEN			(1U<<0)
#define ADC1EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define AD_SEQ_LEN_1 	0x00
#define CR2_ADCON		(1U<<0)
#define CR2_CONT		(1U<<1)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)

void pa1_adc_init(void){
	//Configure the ADC GPIO pin
	RCC->AHB1ENR |= GPIOAEN; //Enable clock access to GPIOA
	GPIOA->MODER |= (1U<<2); //Set PA1 mode to analog mode
	GPIOA->MODER |= (1U<<3);
	//Configure the ADC Module
	RCC->APB2ENR |= ADC1EN; //Enable clock access to the ADC module
	ADC1->SQR3 = ADC_CH1; //Set conversion swquence start
	ADC1->SQR1 = AD_SEQ_LEN_1; //Set conversion sequence length
	ADC1->CR2 |= CR2_ADCON; //Enable ADC module
}

void start_conversion(void){
	ADC1->CR2 |= CR2_CONT; //Enable continous conversion
	ADC1->CR2 |= CR2_SWSTART; //Start ADC conversion
}

uint32_t adc_read(void){
	while(!(ADC1->SR & SR_EOC)){} //Wait for conversion to be complete
	return (ADC1->DR); //Read converted value
}

