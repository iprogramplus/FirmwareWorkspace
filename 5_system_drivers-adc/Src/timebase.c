#include "timebase.h"
#include "stm32f4xx.h"

#define CTRL_ENABLE		(1U<<0)
#define CTRL_TICKINT	(1U<<1)
#define CTRL_CLCKSRC	(1U<<2)
#define CTRL_COUNTFLAG	(1U<<16)

#define ONE_SEC_LOAD	160000000

#define MAX_DELAY		0xFFFFFFFF

#define TICK_FREQ		1

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

void delay(uint32_t delay){
	uint32_t tickstart = get_tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY){
		wait += (uint32_t)TICK_FREQ;
	}

	while((get_tick() - tickstart) < wait){}
}

uint32_t get_tick(void){
	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();
	return g_curr_tick_p;
}

static void tick_increment(void){
	g_curr_tick += TICK_FREQ;
}

void timebase_init(void){
	__disable_irq();		//Disable global interrupts
	SysTick->LOAD = ONE_SEC_LOAD - 1;	//Load the timer with number of clock cycles per second
	SysTick->VAL = 0;		//Clear systick current value register
	SysTick->CTRL = CTRL_CLCKSRC;		//Select internal clock source
	SysTick->CTRL |= CTRL_TICKINT;		//Enable interrupts
	SysTick->CTRL |= CTRL_ENABLE;		//Enable systick
	__enable_irq();		//Enable global interrupts
}

void SysTick_Handler(void){
	tick_increment();
}
