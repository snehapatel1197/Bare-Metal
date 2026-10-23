/*
 * stm32f1xx_gpio_driver.h
 *
 *  Created on: Oct 22, 2026
 *      Author: sneha
 */

#ifndef INC_STM32F103XX_GPIO_DRIVER_H_
#define INC_STM32F103XX_GPIO_DRIVER_H_

#include "stm32f103xx.h"

//GPIO CONFIGURATION STRUCTURE
typedef struct{

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinIOMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinPUPD;
	uint8_t GPIO_PinAltFunMode;

}GPIO_Config_t;

//HANDLE STRUCTURE FOR THE GPIO
typedef struct{

	GPIO_RegDef_t *pGPIOx;																//holds base address of the gpio port to which the pin belongs
	GPIO_Config_t GPIO_PinConfig;														//hold gpio pin configuration setting

}GPIO_Handle_t;

//MACROS FOR GPIO INPUT MODES
#define GPIO_MODE_IP_ANALOG 		0
#define GPIO_MODE_IP_FLOATING		1
#define GPIO_MODE_IP_PUPD 			2
#define GPIO_MODE_IP_RESERVED 		3
#define GPIO_MODE_OUTPUT			4
////MACROS FOR INTTERUPT MODES
#define GPIO_MODE_IT_FT 			5
#define GPIO_MODE_IT_RT 			6
#define GPIO_MODE_IT_RFT 			7

//MACROS FOR GPIO OUTPUT MODES - CNF
#define GPIO_OP_PP 					0
#define GPIO_OP_OD 					1
#define GPIO_OP_AF_PP 				2
#define GPIO_OP_AF_OD 				3

//MACROS FOR GPIO SPEED - MODE
#define GPIO_IN	 				0
#define GPIO_SPEED_10MHz 		1
#define GPIO_SPEED_2MHz 		2
#define GPIO_SPEED_50MHz 		3

//MACROS FOR GPIO PIN
#define GPIO_PIN_PD                0
#define GPIO_PIN_PU                1


//API Supported by this Driver

//periph clock control
void GPIO_PCLKC(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi); 									//Peripheral clock control of the GPIO

//intialization and deintialization
void GPIO_Init(GPIO_Handle_t *pGPIOHandle); 											//Intialize the GPIO
void GPIO_DInit(GPIO_RegDef_t *pGPIOx); 												//DIntialize the GPIO

//read write
uint8_t GPIO_RdIPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber); 						//Read from Input pin of the GPIO
uint16_t GPIO_RdIPPort(GPIO_RegDef_t *pGPIOx);											//Read from Input port of the GPIO
void GPIO_WrOPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value); 			//write to Input pin of the GPIO
void GPIO_WrOPPort(GPIO_RegDef_t *pGPIOx, uint16_t Value); 					   			//Write to Input port of the GPIO
void GPIO_ToggleOPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);						//toggle the gpio pin

//interrupt handling
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);			//IRQ configuration
void GPIO_IRQ_Handling(uint8_t PinNumber); 												//IRQ Handling


#endif
