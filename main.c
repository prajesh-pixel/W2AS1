#include "stm32f10x.h"
void SysClockConfig (void);
void SysClockConfig (void)
{
	
	
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
	
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC_CFGR_ADCPRE & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
	
	
}


int main(void)
{

	SysClockConfig();
	
	for(int i=1;i<=1000;i++){
	
		if(i%5==0){
		
			GPIOC->BSRR |= (1<<13);
			
		}
		else{
			
			GPIOC->BSRR |= ((1<<13)<<16);
			
		}
		
	}
	
}