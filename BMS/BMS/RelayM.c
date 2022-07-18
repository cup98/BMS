#include "RelayM.h"
#include "CAN_Cfg.h"

RelayM_Ctrl_Type ReM_Ctl =					//初始控制继电器
{
	0,
	0,
};

RelayM_Switch_Type ReM_Swi =				//初始切换开关
{
	0,
	0,
};

void RelayM_Init(void)										//继电器模块初始化
{

}

void RelayM_Control(RelayM_Object_Type object ,int state)		//继电器控制函数
{
	if(object == MASTER)									//选中总正继电器
	{
		ReM_Ctl.Master = state;							//把state赋值给选中目标,0:断开,1:闭合
		//CAN_PreStateOut_TestType.Data[3] = state;
		//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	}
	else													//选中预充继电器
	{
		ReM_Ctl.Precharge = state;						//把state赋值给选中目标
		//CAN_PreStateOut_TestType.Data[4] = state;
		//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	}
}

void RelayM_Change(RelayM_Object_Type object ,int state)			//继电器切换函数
{
	if(object == MASTER)									//选中总正继电器
	{
		ReM_Swi.Master  = state;							//把state赋值给选中目标,0:断开,1:闭合
	}
	else													//选中预充继电器
	{
		ReM_Swi.Precharge = state;						//把state赋值给选中目标
	}
}
