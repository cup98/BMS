#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Hv_Voltage_Type 				//获取电压目标
{
	BAT,
	V1,
} Hv_Voltage_Type;

extern void Hv_Init(void); 					//高压管理模块由初始化函数
extern int Hv_Get(Hv_Voltage_Type object);	//获取电压函数

#endif