#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

uint32_t SystemCoreClock = 16000000;

void SystemInit(void) {
    RCC->CR |= RCC_CR_HSION;
    RCC->CFGR = 0x00000000;
    RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_CSSON | RCC_CR_PLLON);
    RCC->PLLCFGR = 0x24003010;
    RCC->CR &= ~(RCC_CR_HSEBYP);
    RCC->CIR = 0x00000000;

    SystemCoreClockUpdate();
}

void SystemCoreClockUpdate(void) {
    SystemCoreClock = 16000000;
}

