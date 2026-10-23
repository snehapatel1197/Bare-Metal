/*
 * stm32f1xx_gpio_driver.c
 *
 *  Created on: Oct 22, 2026
 *      Author: sneha
 */
#include <stddef.h>
#include <stm32f103xx_gpio_driver.h>

void GPIO_PCLKC(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi){ 									//Peripheral clock control of the GPIO
	if(EnorDi == ENABLE){
		if(pGPIOx == GPIOA){GPIOA_PCLK_EN();}
		else if(pGPIOx == GPIOB){GPIOB_PCLK_EN();}
		else if(pGPIOx == GPIOC){GPIOC_PCLK_EN();}
		else if(pGPIOx == GPIOD){GPIOD_PCLK_EN();}
		else if(pGPIOx == GPIOE){GPIOE_PCLK_EN();}
		else if(pGPIOx == GPIOF){GPIOF_PCLK_EN();}
		else if(pGPIOx == GPIOG){GPIOG_PCLK_EN();}
	}
	else{
		if(pGPIOx == GPIOA){GPIOA_PCLK_DI();}
		else if(pGPIOx == GPIOB){GPIOB_PCLK_DI();}
		else if(pGPIOx == GPIOC){GPIOC_PCLK_DI();}
		else if(pGPIOx == GPIOD){GPIOD_PCLK_DI();}
		else if(pGPIOx == GPIOE){GPIOE_PCLK_DI();}
		else if(pGPIOx == GPIOF){GPIOF_PCLK_DI();}
		else if(pGPIOx == GPIOG){GPIOG_PCLK_DI();}
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIOHandle){ 											//Intialize the GPIO

	//GPIO MODE
	uint32_t temp1,temp2;
	uint32_t mode_value;
	uint32_t cnf_value;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber > 15)
	{
		return;
	}

	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
	GPIO_PCLKC(pGPIOHandle->pGPIOx, ENABLE);

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinIOMode == GPIO_MODE_OUTPUT)
	{
		mode_value = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed;
		cnf_value = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType;
	}

	else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinIOMode == GPIO_MODE_IP_ANALOG)
	{
		mode_value = 0;
		cnf_value = 0;
	}

	else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinIOMode == GPIO_MODE_IP_FLOATING)
	{
		mode_value = 0;
		cnf_value = 1;
	}

	else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinIOMode == GPIO_MODE_IP_PUPD)
	{
		mode_value = 0;
		cnf_value = 2;

		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinPUPD == GPIO_PIN_PU)
		{
			pGPIOHandle->pGPIOx->ODR |= (1U << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else
		{
			pGPIOHandle->pGPIOx->ODR &= ~(1U << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
	}

	else
	{
		return;
	}

	if(temp1==0){
		pGPIOHandle->pGPIOx->CRL &= ~(0xF<<(4*temp2));
		pGPIOHandle->pGPIOx->CRL |= (mode_value << (4*temp2));
		pGPIOHandle->pGPIOx->CRL |= (cnf_value << ((4*temp2)+2));
	}else{
		pGPIOHandle->pGPIOx->CRH &= ~(0xF<<(4*temp2));
		pGPIOHandle->pGPIOx->CRH |= (mode_value << (4*temp2));
		pGPIOHandle->pGPIOx->CRH |= (cnf_value << ((4*temp2)+2));
	}
}

void GPIO_DInit(GPIO_RegDef_t *pGPIOx){ 												//DIntialize the GPIO
	if(pGPIOx == GPIOA){GPIOA_RESET();}
	else if(pGPIOx == GPIOB){GPIOB_RESET();}
	else if(pGPIOx == GPIOC){GPIOC_RESET();}
	else if(pGPIOx == GPIOD){GPIOD_RESET();}
	else if(pGPIOx == GPIOE){GPIOE_RESET();}
	else if(pGPIOx == GPIOF){GPIOF_RESET();}
	else if(pGPIOx == GPIOG){GPIOG_RESET();}
}

//read write
uint8_t GPIO_RdIPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){ 						//Read from Input pin of the GPIO
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}
uint16_t GPIO_RdIPPort(GPIO_RegDef_t *pGPIOx){ 											//Read from Input port of the GPIO
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WrOPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){ 			//write to Input pin of the GPIO
	if(Value == GPIO_PIN_SET){
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WrOPPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){ 							//Write to Input port of the GPIO

	pGPIOx->ODR = Value;

}

void GPIO_ToggleOPPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){						//toggle the gpio pin

	pGPIOx->ODR ^= (1 << PinNumber);

}
//interrupt handling
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);			//IRQ configuration
void GPIO_IRQ_Handling(uint8_t PinNumber); 												//IRQ Handling



