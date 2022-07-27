#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"

typedef enum _RelayM_Object_Type   		//构建继电器控制目标
{
	MASTER,
	PRECHANG,
} RelayM_Object_Type;

typedef struct _RelayM_CtrlType			//继电器目标状态
{
	int Master;							//总正继电器
	int Precharge;						//预充继电器
} RelayM_CtrlType;

typedef struct _RelayM_SwitchType		//开关目标状态
{
	int Master;							//总正开关
	int Precharge;						//预充开关
} RelayM_SwitchType;

extern void RelayM_Init(void);										//继电器模块由初始化函数
extern void RelayM_Control(RelayM_Object_Type object ,int state);	//控制继电器开关函数,控制继电器开关函数(控制目标,状态)
extern void RelayM_Change(RelayM_Object_Type object ,int state);	//切换开关函数,切换开关函数(控制目标,状态)

#endif