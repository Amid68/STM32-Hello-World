/**
 * @file main.c
 * @brief Main entry point for the STM32 Nucleo-F446RE Hello World project.
 *
 * This file contains the main function which initializes the system clock,
 * configures the onboard LED, and toggles the LED in an infinite loop.
 * The project is designed for the STM32 Nucleo-F446RE board and demonstrates
 * basic GPIO functionality.
 *
 * @author Ameed Othman
 * @date 2024-11-17
 *
 * @note This project uses a modular structure with separate files for 
 *       clock configuration and LED control. The delay in the main loop
 *       is implemented using a simple software loop.
 */
#include "stm32f44x.h"
#include "led.h"
#include "clock_config.h"

int main(void) {
    SystemInit();
    SystemClock_Config();
    LED_Init();

    while (1) {
        LED_Toggle();
        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}

