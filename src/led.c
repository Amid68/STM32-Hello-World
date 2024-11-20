/************************************************************************************
 * @file led.c                                                                      *
 * @brief LED control module for STM32 Nucleo-F446RE.                               *
 *                                                                                  *
 * This file provides the implementation for initializing and toggling the LED      *
 * connected to GPIO pin PA5 on the STM32 Nucleo-F446RE board.                      *            
 * It configures the GPIO pin and provides a simple interface to control the LED.   *
 *                                                                                  *
 * @author Ameed Othman                                                             *
 * @date 2024-11-17                                                                 *
 ************************************************************************************/ 
#include "stm32f4xx.h"
#include "led.h"

/************************************************************************************
 * @brief Initializes the onboard LED (PA5).                                        *
 *                                                                                  *
 * This function configures the GPIOA pin 5 as an output pin with the default       *
 * settings (push-pull, no pull-up/pull-down resistors). It ensures that the        *
 * GPIOA peripheral clock is enabled before configuring the pin.                    *
 *                                                                                  *
 * @note Make sure the RCC clock for GPIOA is enabled before calling this function. *
 ************************************************************************************/
void LED_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    
    GPIOA->MODER &= ~(GPIO_MODER_MODER5_Msk);
    GPIOA->MODER |= (1 << GPIO_MODER_MODER5_Pos);

    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5);
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);
}

/****************************************************************************
 * @brief Toggles the state of the onboard LED (PA5).                       *
 *                                                                          *
 * This function toggles the output state of GPIOA pin 5, turning the LED   *
 * on if it was off and vice versa.                                         *    
 *                                                                          *
 * @note LED_Init() must be called before using this function.              *
 ****************************************************************************/
void LED_Toggle(void) {
    GPIOA->ODR ^= GPIO_ODR_OD5;
}

