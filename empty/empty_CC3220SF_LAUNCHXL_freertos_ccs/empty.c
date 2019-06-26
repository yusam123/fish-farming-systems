  /*
   *  ======== empty.c ========
   */

  /* For usleep() */
  #include <unistd.h>
  #include <stdint.h>
  #include <stddef.h>

  /* Driver Header files */
  #include <ti/drivers/GPIO.h>
//  #include <ti/drivers/ADC.h>
  #include <ti/display/Display.h>
  // #include <ti/drivers/I2C.h>
  // #include <ti/drivers/SDSPI.h>
  // #include <ti/drivers/SPI.h>
  // #include <ti/drivers/UART.h>
  // #include <ti/drivers/Watchdog.h>

  /* Board Header file */
  #include "Board.h"

/*
 *  ======== gpioButtonFxn0 ========
 *  Callback function for the GPIO interrupt on Board_GPIO_BUTTON0.
 */
void gpioButtonFxn0(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_LED0);
}

/*
 *  ======== gpioButtonFxn1 ========
 *  Callback function for the GPIO interrupt on Board_GPIO_BUTTON1.
 *  This may not be used for all boards.
 */
void gpioButtonFxn1(uint_least8_t index)
{
    /* Clear the GPIO interrupt and toggle an LED */
    GPIO_toggle(Board_GPIO_LED1);
}

  /*
   *  ======== mainThread ========
   */

  void *mainThread(void *arg0)
  {


    /* Call driver init functions */
    GPIO_init();
    //ADC_init();
    // I2C_init();
    // SDSPI_init();
    // SPI_init();
     UART_init();
    // Watchdog_init();
    gpio_config_setup();
    /* Open Display Driver */
    Display_Handle    displayHandle;
    Display_Params    displayParams;
    Display_Params_init(&displayParams);
    displayHandle = Display_open(Display_Type_UART, NULL);


    while (1) {
        int i=0;
        for(i=Board_GPIO_28;i<Board_GPIO_22;i++){
        if(GPIO_read(i)){
         Display_printf(displayHandle, 1, 0, "fffff" );
         GPIO_toggle(Board_GPIO_14);
        }
        }
        sleep(1);
    }
  }

  void *secondThread(void *arg0)
  {
      /* Call driver init functions */
      GPIO_init();

      /* Configure the LED and button pins */
      GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
      GPIO_setConfig(Board_GPIO_LED1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
      GPIO_setConfig(Board_GPIO_BUTTON0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

      /* Turn on user LED */
      GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_ON);

      /* install Button callback */
      GPIO_setCallback(Board_GPIO_BUTTON0, gpioButtonFxn0);

      /* Enable interrupts */
      GPIO_enableInt(Board_GPIO_BUTTON0);

      /*
       *  If more than one input pin is available for your device, interrupts
       *  will be enabled on Board_GPIO_BUTTON1.
       */
      if (Board_GPIO_BUTTON0 != Board_GPIO_BUTTON1) {
          /* Configure BUTTON1 pin */
          GPIO_setConfig(Board_GPIO_BUTTON1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

          /* Install Button callback */
          GPIO_setCallback(Board_GPIO_BUTTON1, gpioButtonFxn1);
          GPIO_enableInt(Board_GPIO_BUTTON1);
      }

      return (NULL);
  }
