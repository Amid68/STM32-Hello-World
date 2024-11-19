#ifndef __SYSTEM_STM32F4XX_H__
#define __SYSTEM_STM32F4XX_H__

#include <stdint.h>

extern uint32_t SystemCoreClock;

void SystemInit(void);
void SystemCoreClockUpdate(void);

#endif
