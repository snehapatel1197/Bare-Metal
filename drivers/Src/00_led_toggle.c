/*
 * 00_led_toggle.c
 *
 *  Created on: 22-Oct-2026
 *      Author: sneha
 */



#include "stm32f103xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i=0;i<500000;i++);
}

int main(void)
{
    GPIO_Handle_t GpioLed;

    GpioLed.pGPIOx = GPIOC;

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = 13;
    GpioLed.GPIO_PinConfig.GPIO_PinIOMode = GPIO_MODE_OUTPUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_2MHz;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_OD;
    GpioLed.GPIO_PinConfig.GPIO_PinPUPD = GPIO_PIN_PD;

    GPIO_PCLKC(GPIOC,ENABLE);
    GPIO_Init(&GpioLed);

    while(1)
    {
    	GPIO_ToggleOPPIN(GPIOC,13);
    	delay();
    }
}
