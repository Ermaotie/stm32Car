#ifndef __ALARM_H
#define __ALARM_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include "vl53l0x.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK NANO STM32������
//VL53L0X-�жϲ���ģʽ ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2018/7/18
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2018-2028
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

void vl53l0x_interrupt_test(VL53L0X_Dev_t *dev,u8 mode);


#endif 
