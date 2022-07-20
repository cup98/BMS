#include "RelayM.h"
#include "CAN_Cfg.h"

RelayM_CtrlType ReM_Ctl =									//初始化继电器状态
{
	0,
	0,
};

RelayM_SwitchType ReM_Swi =									//初始化开关状态
{
	0,
	0,
};

void RelayM_Init(void)										//继电器模块由初始化函数
{
}

void RelayM_Control(RelayM_Object_Type object ,int state)	//控制继电器开关函数(控制目标,状态)
{
	if(object == MASTER)
	{
		ReM_Ctl.Master = state;
	}
	else
	{
		ReM_Ctl.Precharge = state;
	}
}

void RelayM_Change(RelayM_Object_Type object ,int state)	//切换开关函数(控制目标,状态)
{
	if(object == MASTER)
	{
		ReM_Swi.Master  = state;
	}
	else
	{
		ReM_Swi.Precharge = state;
	}
}
