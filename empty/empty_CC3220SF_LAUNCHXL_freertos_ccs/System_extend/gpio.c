/*
 * gpio.c
 *
 *  Created on: 2019¦~6¤ë8¤é
 *      Author: DL1080
 */
#include <ti/drivers/GPIO.h>
#include "Board.h"
void gpio_config_setup(void){
    GPIO_setConfig(Board_GPIO_28, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_08, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_17, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_16, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_30, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_00, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_23, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_22, GPIO_CFG_IN_PD | GPIO_CFG_IN_INT_FALLING);
}



