/*
 * gpio.h
 *
 *  Created on: 2019年4月21日
 *      Author: yusam
 */

#ifndef APPLICATION_CODE_COMMON_DEMOS_INCLUDE_GPIO_H_
#define APPLICATION_CODE_COMMON_DEMOS_INCLUDE_GPIO_H_

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC32XX.h>
#include "Board.h"
/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "message_buffer.h"
/* For usleep() */
#include <unistd.h>                    //問該怎麼跳出回圈
#include <stddef.h>
#include "status_control.h"

void opengpio (int pin){
    pin=pin+5;
    GPIO_toggle(pin);
}
void gpiosetup(void){
    int i;
    for(i=5;i<13;i++){
        GPIO_write(i, Board_GPIO_OPEN );
    }
}
/*
 *  ======== gpioButtonFxn0 ========
 *  Callback function for the GPIO interrupt on Board_GPIO_BUTTON0.
 */
void gpioButtonFxn0(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P5);
}
/*
 *  ======== gpioButtonFxn1 ========
 *  Callback function for the GPIO interrupt on Board_GPIO_BUTTON1.
 *  This may not be used for all boards.
 */
void gpioButtonFxn1(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P50);
}
void gpioButtonFxn2(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P3);
}
void gpioButtonFxn3(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P61);
}
void gpioButtonFxn4(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P18);
}
void gpioButtonFxn5(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P62);
}
void gpioButtonFxn6(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P63);
}
void gpioButtonFxn7(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_P53);
}
/*
 *  ======== mainThread ========
 */
void buttom(void)
{
//    /* Call driver init functions */
//    GPIO_init();
//
//    /* Configure the LED and button pins */
//    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
//    GPIO_setConfig(Board_GPIO_LED1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(Board_GPIO_BUTTON0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
//    GPIO_setConfig(Board_GPIO_P8,  GPIO_CFG_INPUT | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(Board_GPIO_P45, GPIO_CFG_INPUT | GPIO_CFG_IN_INT_FALLING);
//    GPIO_setConfig(Board_GPIO_P7,  GPIO_CFG_INPUT | GPIO_CFG_IN_INT_FALLING);       //無法使用
//    GPIO_setConfig(Board_GPIO_P6, GPIO_CFG_INPUT  | GPIO_CFG_IN_INT_FALLING);       //無法使用
//    GPIO_setConfig(Board_GPIO_P21,  GPIO_CFG_INPUT | GPIO_CFG_IN_INT_FALLING);      //無法使用
//    GPIO_setConfig(Board_GPIO_P55, GPIO_CFG_INPUT | GPIO_CFG_IN_INT_FALLING);       //無法使用
//    /* Turn on user LED */
//    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_ON);
//
//    /* install Button callback */
    GPIO_setCallback(Board_GPIO_BUTTON0, gpioButtonFxn0);
//
//    /* Enable interrupts */
    GPIO_enableInt(Board_GPIO_BUTTON0);
//
//    /*
//     *  If more than one input pin is available for your device, interrupts
//     *  will be enabled on Board_GPIO_BUTTON1.
//     */
    if (Board_GPIO_BUTTON0 != Board_GPIO_BUTTON1) {
        /* Configure BUTTON1 pin */
        GPIO_setConfig(Board_GPIO_BUTTON1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

        /* Install Button callback */
        GPIO_setCallback(Board_GPIO_BUTTON1, gpioButtonFxn1);
        GPIO_enableInt(Board_GPIO_BUTTON1);
    }
    if (Board_GPIO_BUTTON0 != Board_GPIO_BUTTON1) {
            /* Configure BUTTON1 pin */
           GPIO_setConfig(Board_GPIO_P8,  GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

            /* Install Button callback */
            GPIO_setCallback(Board_GPIO_P8 , gpioButtonFxn2);
            GPIO_enableInt(Board_GPIO_P8 );
        }
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P8 , gpioButtonFxn2);

//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P8 );
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P45 , gpioButtonFxn3);
//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P45 );
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P7 , gpioButtonFxn4);
//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P7 );
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P6 , gpioButtonFxn5);
//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P6 );
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P21 , gpioButtonFxn6);
//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P21 );
//        /* install Button callback */
//        GPIO_setCallback(Board_GPIO_P55 , gpioButtonFxn7);
//        /* Enable interrupts */
//        GPIO_enableInt(Board_GPIO_P55 );
//
//   // return (NULL);
}

#endif /* APPLICATION_CODE_COMMON_DEMOS_INCLUDE_GPIO_H_ */
