/*
 * status_control.h
 *
 *  Created on: 2019年4月23日
 *      Author: yusam
 */

#ifndef APPLICATION_CODE_COMMON_DEMOS_INCLUDE_STATUS_CONTROL_H_
#define APPLICATION_CODE_COMMON_DEMOS_INCLUDE_STATUS_CONTROL_H_

int flag = 1;             //用來控制mqtt發佈端跳出無限迴圈，結束發佈mqtt訊息
int flag_pwm=0;           //控制pwm開啟跟結束
int flag_gpio[8] = {0};


#endif /* APPLICATION_CODE_COMMON_DEMOS_INCLUDE_STATUS_CONTROL_H_ */
