#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"

typedef enum _RelayM_Object_Type
{
	MASTER,
	PRECHANG,
} RelayM_Object_Type;

typedef struct _RelayM_Ctrl_Type		    //构建继电器控制结构体
{
	int Master;					//总正控制
	int Precharge;				//预充控制
} RelayM_Ctrl_Type;

typedef struct _RelayM_Switch_Type			//构建开关切换结构体
{
	int Master;					//总正切换
	int Precharge;				//预充切换
} RelayM_Switch_Type;

//继电器模块初始化函数
extern void RelayM_Init();

//控制继电器开关函数
extern void RelayM_Control(RelayM_Object_Type object ,int state);		//控制总正和预充继电器的开关

//切换开关函数
extern void RelayM_Change(RelayM_Object_Type object ,int state);		//控制总正和预充开关的切换

#endif