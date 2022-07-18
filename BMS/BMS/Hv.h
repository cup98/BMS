#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Hv_Voltage_Type
{
	BAT,
	V1
} Hv_Voltage_Type;

//高压管理模块初始化函数
extern void Hv_Init();
//获取电压函数
extern int Hv_Get(Hv_Voltage_Type object);		//获取当前BAT或V1电压

#endif