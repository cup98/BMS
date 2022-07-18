#include "RelayM.h"

void RelayM_Init(void)										//继电器模块初始化
{

}

void RelayM_Control(RelayM_Object_Type Object ,int state)		//继电器控制函数
{
	if(object == MASTER)									//选中总正继电器
	{
		RelayM_Ctrl_Type.Master_State = state;							//把state赋值给选中目标,0:断开,1:闭合
	}
	else													//选中预充继电器
	{
		RelayM_Ctrl_Type.Precharge_State = state;						//把state赋值给选中目标
	}
}

void RelayM_Change(RelayM_Object_Type object ,int state)			//继电器切换函数
{
	if(object == MASTER)									//选中总正继电器
	{
		RelayM_Switch_Type.Master_State  = state;							//把state赋值给选中目标,0:断开,1:闭合
	}
	else													//选中预充继电器
	{
		RelayM_Switch_Type.Precharge_State = state;						//把state赋值给选中目标
	}
}
