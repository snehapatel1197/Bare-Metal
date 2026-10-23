/*
 * stm32f103xx.h
 *
 *  Created on: Oct 21, 2026
 *      Author: sneha
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include<stdint.h>

#define __vo volatile
//base address of the flash and sram

#define FLASH_BASEADDR					0x08000000U
#define SRAM_BASEADDR					0x20000000U
#define SRAM							SRAM_BASEADDR
#define ROM_BASEADDR					0x1FFFF000U

//PERIPHERAL BASE ADDRESS OF THE APBx AND AHBx

#define PERIPH_BASE				    	0x40000000U
#define APB1PERIPH_BASEADDR				PERIPH_BASE
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHBPERIPH_BASEADDR				0x40020000U

//BASE ADDRESSES OF THE PERIPHERALS WHICH ARE ON THE APB2 BUS
#define EXTI_BASEADDR				    (APB2PERIPH_BASEADDR+0x0400)

#define GPIOA_BASEADDR				    (APB2PERIPH_BASEADDR+0x0800)
#define GPIOB_BASEADDR				    (APB2PERIPH_BASEADDR+0x0C00)
#define GPIOC_BASEADDR				    (APB2PERIPH_BASEADDR+0x1000)
#define GPIOD_BASEADDR				    (APB2PERIPH_BASEADDR+0x1400)
#define GPIOE_BASEADDR				    (APB2PERIPH_BASEADDR+0x1800)
#define GPIOF_BASEADDR				    (APB2PERIPH_BASEADDR+0x1C00)
#define GPIOG_BASEADDR				    (APB2PERIPH_BASEADDR+0x2000)

#define SPI1_BASEADDR				    (APB2PERIPH_BASEADDR+0x3000)

#define USART1_BASEADDR				    (APB2PERIPH_BASEADDR+0x3800)


//BASE ADDRESSES OF THE PERIPHERALS WHICH ARE ON THE APB1 BUS
#define SPI2_BASEADDR				    (APB1PERIPH_BASEADDR+0x3800)
#define SPI3_BASEADDR				    (APB1PERIPH_BASEADDR+0x3C00)

#define USART2_BASEADDR				    (APB1PERIPH_BASEADDR+0x4400)
#define USART3_BASEADDR				    (APB1PERIPH_BASEADDR+0x4800)

#define UART4_BASEADDR				    (APB1PERIPH_BASEADDR+0x4C00)
#define UART5_BASEADDR				    (APB1PERIPH_BASEADDR+0x5000)

#define I2C1_BASEADDR				    (APB1PERIPH_BASEADDR+0x5400)
#define I2C2_BASEADDR				    (APB1PERIPH_BASEADDR+0x5800)

//BASE ADDRESSES OF THE PERIPHERALS WHICH ARE ON THE AHB BUS
#define RCC_BASEADDR					(AHBPERIPH_BASEADDR+0x1000)

//GPIO MODES
typedef struct{

	__vo uint32_t CRL;					//Port configuration register low		ADDRESS OFFSET 0x00
	__vo uint32_t CRH;					//Port configuration register high		ADDRESS OFFSET 0x04
	__vo uint32_t IDR;					//Port input data register				ADDRESS OFFSET 0x08
	__vo uint32_t ODR;					//Port output data register 			ADDRESS OFFSET 0x0C
	__vo uint32_t BSRR;					//Port bit set/reset register			ADDRESS OFFSET 0x10
	__vo uint32_t BRR;					//Port bit reset register				ADDRESS OFFSET 0x14
	__vo uint32_t LCKR;					//Port configuration lock register 		ADDRESS OFFSET 0x18

}GPIO_RegDef_t;

//PERIPHERALS DEFINATIONS

#define GPIOA 							((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 							((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 							((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 							((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 							((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 							((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 							((GPIO_RegDef_t*)GPIOG_BASEADDR)

//RCC
typedef struct{

	__vo uint32_t CR;					//Clock control register 				ADDRESS OFFSET 0x00
	__vo uint32_t CFGR;					//Clock configuration register			ADDRESS OFFSET 0x04
	__vo uint32_t CIR;					//Clock interrupt register				ADDRESS OFFSET 0x08
	__vo uint32_t APB2RSTR;				//APB2 peripheral reset register 		ADDRESS OFFSET 0x0C
	__vo uint32_t APB1RSTR;				//APB1 peripheral reset register		ADDRESS OFFSET 0x10
	__vo uint32_t AHBENR;				//AHB peripheral clock enable register	ADDRESS OFFSET 0x14
	__vo uint32_t APB2ENR;				//APB2 peripheral clock enable register ADDRESS OFFSET 0x18
	__vo uint32_t APB1ENR;				//APB1 peripheral clock enable register ADDRESS OFFSET 0x1C
	__vo uint32_t BDCR;					//Backup domain control register 		ADDRESS OFFSET 0x20
	__vo uint32_t CSR;					//Control/status register  				ADDRESS OFFSET 0x24

}RCC_RegDef_t;

#define RCC 							((RCC_RegDef_t*)RCC_BASEADDR)

//CLOCK ENABLE MACROS FOR GPIO
#define GPIOA_PCLK_EN()					(RCC->APB2ENR |= (1 << 2))
#define GPIOB_PCLK_EN()					(RCC->APB2ENR |= (1 << 3))
#define GPIOC_PCLK_EN()					(RCC->APB2ENR |= (1 << 4))
#define GPIOD_PCLK_EN()					(RCC->APB2ENR |= (1 << 5))
#define GPIOE_PCLK_EN()					(RCC->APB2ENR |= (1 << 6))
#define GPIOF_PCLK_EN()					(RCC->APB2ENR |= (1 << 7))
#define GPIOG_PCLK_EN()					(RCC->APB2ENR |= (1 << 8))

//CLOCK DISABLE MACROS FOR GPIO
#define GPIOA_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 2))
#define GPIOB_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 3))
#define GPIOC_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 4))
#define GPIOD_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 5))
#define GPIOE_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 6))
#define GPIOF_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 7))
#define GPIOG_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 8))

//PERIPHERAL DISABLE MACROS
#define GPIOA_RESET()					do {(RCC->APB2RSTR |= (1<<2)); (RCC->APB2RSTR &= ~(1<<2));} while(0)
#define GPIOB_RESET()					do {(RCC->APB2RSTR |= (1<<3)); (RCC->APB2RSTR &= ~(1<<3));} while(0)
#define GPIOC_RESET()					do {(RCC->APB2RSTR |= (1<<4)); (RCC->APB2RSTR &= ~(1<<4));} while(0)
#define GPIOD_RESET()					do {(RCC->APB2RSTR |= (1<<5)); (RCC->APB2RSTR &= ~(1<<5));} while(0)
#define GPIOE_RESET()					do {(RCC->APB2RSTR |= (1<<6)); (RCC->APB2RSTR &= ~(1<<6));} while(0)
#define GPIOF_RESET()					do {(RCC->APB2RSTR |= (1<<7)); (RCC->APB2RSTR &= ~(1<<7));} while(0)
#define GPIOG_RESET()					do {(RCC->APB2RSTR |= (1<<8)); (RCC->APB2RSTR &= ~(1<<8));} while(0)

//GENERIC MACROS
#define ENABLE 							1
#define DISABLE 						0
#define SET 							ENABLE
#define RESET 							DISABLE
#define GPIO_PIN_SET 					SET
#define GPIO_PIN_RESET 					RESET

//CLOCK ENABLE MACROS FOR I2C
//CLOCK ENABLE MACROS FOR SPI
//CLOCK ENABLE MACROS FOR UART
//CLOCK ENABLE MACROS FOR USART

//CLOCK DISABLE MACROS FOR I2C
//CLOCK DISABLE MACROS FOR SPI
//CLOCK DISABLE MACROS FOR UART
//CLOCK DISABLE MACROS FOR USART


#endif /* INC_STM32F103XX_H_ */
