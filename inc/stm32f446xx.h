#ifndef __STM32F446XX_H__
#define __STM32F446XX_H__

#include <stdint.h>

#define __IO volatile

/* Base addresses */
#define PERIPH_BASE     0x40000000UL
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)

#define GPIOA_BASE      (AHB1PERIPH_BASE + 0x0000UL)
#define RCC_BASE        (AHB1PERIPH_BASE + 0x3800UL)


/* GPIO registers structure */
typedef struct {
    __IO uint32_t MODER;    /* GPIO port mode register */
    __IO uint32_t OTYPER;   /* GPIO port output type register */
    __IO uint32_t OSPEEDR;  /* GPIO port output speed register */
    __IO uint32_t PUPDR;    /* GPIO port pull-up/pull-down register */
    __IO uint32_t IDR;      /* GPIO port input data register */
    __IO uint32_t ODR;      /* GPIO port output data register */
    __IO uint32_t BSRR;     /* GPIO port bit set/reset register */
    __IO uint32_t LCKR;     /* GPIO port configuration lock registers */
    __IO uint32_t AFR[2];   /* GPIO alternate function registers */
} GPIO_TypeDef;

/* RCC registers structure */
typedef struct {
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    uint32_t RESERVED0[3];
    __IO uint32_t APB1RSTR;
    uint32_t RESERVED1[3];
    __IO uint32_t AHB1ENR;
    uint32_t RESERVED2[7];
    __IO uint32_t AHB1LPENR;
    uint32_t RESERVED3[7];
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
} RCC_TypeDef;

/* Peripheral instances */
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define RCC     ((RCC_TypeDef *) RCC_BASE)

/* RCC AHB1 peripheral clock enable register */
#define RCC_AHB1ENR_GPIOAEN_Pos (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN     RCC_AHB1ENR_GPIOAEN_Msk

/* GPIO port mode register */
#define GPIO_MODER_MODER5_Pos   (10U)
#define GPIO_MODER_MODER5_Msk   (0x3UL << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5       GPIO_MODER_MODER5_Msk

/* GPIO port output type register */
#define GPIO_OTYPER_OT5_Pos     (5U)
#define GPIO_OTYPER_OT5_Msk     (0x1UL << GPIO_OTYPER_OT5_Pos)
#define GPIO_OTYPER_OT5         GPIO_OTYPER_OT5_Msk

/* GPIO port pull-up/pull-down register */
#define GPIO_PUPDR_PUPD5_Pos    (10U)
#define GPIO_PUPDR_PUPD5_Msk    (0x3UL << GPIO_PUPDR_PUPD5_Pos)
#define GPIO_PUPDR_PUPD5        GPIO_PUPDR_PUPD5_Msk

/* GPIO port output data register */
#define GPIO_ODR_OD5_Pos        (5U)
#define GPIO_ODR_OD5_Msk        (0x1UL << GPIO_ODR_OD5_Pos)
#define GPIO_ODR_OD5            GPIO_ODR_OD5_Msk

/* RCC clock control register */
#define RCC_CR_HSION_Pos        (0U)
#define RCC_CR_HSION_Msk        (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSION            RCC_CR_HSION_Msk

#define RCC_CR_HSEON_Pos        (16U)
#define RCC_CR_HSEON_Msk        (0x1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON            RCC_CR_HSEON_Msk

#define RCC_CR_CSSON_Pos        (19U)
#define RCC_CR_CSSON_Msk        (0x1UL << RCC_CR_CSSON_Pos)
#define RCC_CR_CSSON            RCC_CR_CSSON_Msk

#define RCC_CR_PLLON_Pos        (24U)
#define RCC_CR_PLLON_Msk        (0x1UL << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLON            RCC_CR_PLLON_Msk

#define RCC_CR_HSEBYP_Pos       (18U)
#define RCC_CR_HSEBYP_Msk       (0x1UL << RCC_CR_HSEBYP_Pos)
#define RCC_CR_HSEBYP           RCC_CR_HSEBYP_Msk

#endif
