/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __BOARD_H
#define __BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/ADC.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/I2S.h>
#include <ti/drivers/PWM.h>
#include <ti/drivers/SD.h>
#include <ti/drivers/SDFatFS.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/Watchdog.h>

#include "CC3220SF_LAUNCHXL.h"

#define Board_initGeneral            CC3220SF_LAUNCHXL_initGeneral

#define Board_ADC0                   CC3220SF_LAUNCHXL_ADC0                      //要記得去"CC3220SF_LAUNCHXL.h"定義歐！！
#define Board_ADC1                   CC3220SF_LAUNCHXL_ADC1
#define Board_ADC2                   CC3220SF_LAUNCHXL_ADC2

#define Board_CAPTURE0               CC3220SF_LAUNCHXL_CAPTURE0
#define Board_CAPTURE1               CC3220SF_LAUNCHXL_CAPTURE1

#define Board_CRYPTO0                CC3220SF_LAUNCHXL_CRYPTO0

#define Board_GPIO_LED_ON            CC3220SF_LAUNCHXL_GPIO_LED_ON
#define Board_GPIO_LED_OFF           CC3220SF_LAUNCHXL_GPIO_LED_OFF
#define Board_GPIO_LED0              CC3220SF_LAUNCHXL_GPIO_LED_D7              //自己加入定義

#define Board_GPIO_OPEN              (1)
#define Board_GPIO_CLOSE             (0)

//#define Board_GPIO_1
/*
 *  CC3220SF_LAUNCHXL_GPIO_LED_D5 and CC3220SF_LAUNCHXL_GPIO_LED_D6 are shared with the I2C
 *  and PWM peripherals. In order for those examples to work, these LEDs are
 *  taken out of gpioPinCOnfig[]
 */
#define Board_GPIO_LED1              CC3220SF_LAUNCHXL_GPIO_LED_D6
#define Board_GPIO_LED2              CC3220SF_LAUNCHXL_GPIO_LED_D5

#define Board_GPIO_BUTTON0           CC3220SF_LAUNCHXL_GPIO_SW2
#define Board_GPIO_BUTTON1           CC3220SF_LAUNCHXL_GPIO_SW3                            //input part
#define Board_GPIO_P8                CC3220SF_LAUNCHXL_GPIO_P8
#define Board_GPIO_P45                CC3220SF_LAUNCHXL_GPIO_P45
#define Board_GPIO_P7                CC3220SF_LAUNCHXL_GPIO_P7
#define Board_GPIO_P6                CC3220SF_LAUNCHXL_GPIO_P6
#define Board_GPIO_P21                CC3220SF_LAUNCHXL_GPIO_P21
#define Board_GPIO_P55                CC3220SF_LAUNCHXL_GPIO_P55





#define Board_GPIO_P5                CC3220SF_LAUNCHXL_GPIO_P5                              //將定義加入
#define Board_GPIO_P50                CC3220SF_LAUNCHXL_GPIO_P50
#define Board_GPIO_P3                CC3220SF_LAUNCHXL_GPIO_P3
#define Board_GPIO_P61                CC3220SF_LAUNCHXL_GPIO_P61
#define Board_GPIO_P18               CC3220SF_LAUNCHXL_GPIO_P18
#define Board_GPIO_P62                CC3220SF_LAUNCHXL_GPIO_P62
#define Board_GPIO_P63                CC3220SF_LAUNCHXL_GPIO_P63
#define Board_GPIO_P53                CC3220SF_LAUNCHXL_GPIO_P53

#define Board_I2C0                   CC3220SF_LAUNCHXL_I2C0
#define Board_I2C_TMP                CC3220SF_LAUNCHXL_I2C0

#define Board_I2S0                   CC3220SF_LAUNCHXL_I2S0

#define Board_PWM0                   CC3220SF_LAUNCHXL_PWM6
#define Board_PWM1                   CC3220SF_LAUNCHXL_PWM7
#define Board_PWM2                   CC3220SF_LAUNCHXL_PWM00

#define Board_SD0                    CC3220SF_LAUNCHXL_SD0

#define Board_SDFatFS0               CC3220SF_LAUNCHXL_SD0

/* CC3220SF_LAUNCHXL_SPI0 is reserved for the NWP */
#define Board_SPI0                   CC3220SF_LAUNCHXL_SPI1
#define Board_SPI_MASTER             CC3220SF_LAUNCHXL_SPI1
#define Board_SPI_SLAVE              CC3220SF_LAUNCHXL_SPI1
#define Board_SPI_MASTER_READY       CC3220SF_LAUNCHXL_SPI_MASTER_READY
#define Board_SPI_SLAVE_READY        CC3220SF_LAUNCHXL_SPI_SLAVE_READY

#define Board_TIMER0                 CC3220SF_LAUNCHXL_TIMER0
#define Board_TIMER1                 CC3220SF_LAUNCHXL_TIMER1
#define Board_TIMER2                 CC3220SF_LAUNCHXL_TIMER2

#define Board_UART0                  CC3220SF_LAUNCHXL_UART0
#define Board_UART1                  CC3220SF_LAUNCHXL_UART1

#define Board_WATCHDOG0              CC3220SF_LAUNCHXL_WATCHDOG0

/* Board specific I2C address */
#define Board_TMP006_ADDR            (0x41)
#define Board_I2C_TMP006_ADDR        Board_TMP006_ADDR

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
