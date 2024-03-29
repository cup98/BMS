#include "PrechargeM.h"
#include "Pre_Cfg.h"
#include "CAN_Cfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)			//预充初始化函数
{
}

void PrechargeM_StartPre(void)		//闭合预充开关
{
	RelayM_Control(PRECHANG ,1);
}

void PrechargeM_StopPre(void)		//断开预充开关
{
	RelayM_Control(PRECHANG ,0);
}

void PrechargeM_StartMaster(void)	//闭合总正函数
{
	RelayM_Control(MASTER ,1);
}

void PrechargeM_StopMaster(void)	//断开总正函数
{
	RelayM_Control(MASTER ,0);
}

void PrechargeM_Change(void)		//继电器切换函数
{
	PrechargeM_StartMaster();		//闭合总正
	PrechargeM_StopPre();			//断开预充
}

int PrechargeM_IsFail(void)			//超时判断函数
{									//判断自启动预充至此刻的时间是否超过3秒
	int rebuf;
	if (Pre_Cfg_Clock() <= 3)
	{
		rebuf = 0;
	}
	else
	{
		rebuf = 1;
	}
	return rebuf;
}

int PrechargeM_IsFinish(void)		//预充完成判断函数
{
	int rebuf;
	if (Hv_Get(V1) * 100 >= Hv_Get(BAT) * 95)	//判断V1电压是否大于BAT电压的95%
	{
		rebuf = 1;
	}
	else
	{
		rebuf = 0;
	}
	return rebuf;
}



