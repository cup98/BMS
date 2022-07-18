#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Hv_Voltage_Type
{
	Hv_BAT,
	Hv_V1
} Hv_Voltage_Type;

typedef struct _Get_Hv_Voltage_Type			//构建电压值结构体
{
	int BAT;				//BAT电压
	int V1;					//V1电压
} Get_Hv_Voltage_Type;

Get_Hv_Voltage_Type Get_Hv_V_Type =					//举例电压值
{
	90.0,							//BAT电压为90.0V
	91.0,							//V1电压为91.0V
};


//高压管理模块初始化函数
extern void Hv_Init();
//获取电压函数
extern int Hv_Get(int object);		//获取当前BAT或V1电压

#endif