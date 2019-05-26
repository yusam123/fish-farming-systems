/*
 * adcsinglechannel.h
 *
 *  Created on: 2019年4月5日
 *      Author: yusam
 */

#ifndef APPLICATION_CODE_COMMON_DEMOS_INCLUDE_ADCSINGLECHANNEL_H_
#define APPLICATION_CODE_COMMON_DEMOS_INCLUDE_ADCSINGLECHANNEL_H_

/*
 *  ======== adcsinglechannel.c ========
 */

#include <stdint.h>
#include <stddef.h>
/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "message_buffer.h"

/* POSIX Header files */
#include <pthread.h>

/* Driver Header files */
#include <ti/drivers/ADC.h>
#include <ti/display/Display.h>

/* Example/Board Header files */
#include "Board.h"


/* ADC conversion result variables */
uint16_t adcValue1;
uint32_t adcValue1MicroVolt;

float adcread(int);

float adcread(int pin){

         ADC_Handle   adc;
         ADC_Params   params;
         int_fast16_t res=1;
         ADC_init();
         ADC_Params_init(&params);
         //pin =Board_ADC1
         adc = ADC_open(Board_ADC2, &params);

         if (adc == NULL) {
             configPRINTF(("no Adc singnle"));
         }
         res = ADC_convert(adc, &adcValue1);
         if (res == ADC_STATUS_SUCCESS) {
              adcValue1MicroVolt = ADC_convertRawToMicroVolts(adc, adcValue1);
         }
         ADC_close(adc);
         return (float) adcValue1;
}



#endif /* APPLICATION_CODE_COMMON_DEMOS_INCLUDE_ADCSINGLECHANNEL_H_ */
