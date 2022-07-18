#include "PrechargeM.h"
#include "PreCfg.h"
#include "CAN_Cfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)			//预充电模块初始化
{
}

void PrechargeM_TimeFlag(void)				//时间计数标志位
{
	//i++;
}

void PrechargeM_StartPre(void)		//启动预充
{
	RelayM_Control(PRECHANG ,1);			//闭合预充继电器
	//CAN_PreStateOut_TestType.Data[1] = 0x0A;
	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	//CAN_Delay10ms(10);
}									//开始计数，步长:0.3s

void PrechargeM_StopPre(void)		//断开预充
{
	RelayM_Control(PRECHANG ,0);			//断开预充继电器
	//CAN_PreStateOut_TestType.Data[1] = 0x0B;
	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	//CAN_Delay10ms(10);
}

void PrechargeM_StartMaster(void)	//开始充电
{
	RelayM_Control(MASTER ,1);			//闭合总正继电器
	//CAN_PreStateOut_TestType.Data[1] = 0x0C;
	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	//CAN_Delay10ms(10);
}

void PrechargeM_StopMaster(void)	//停止总正充电
{
	RelayM_Control(MASTER ,0);			//断开总正继电器
	//CAN_PreStateOut_TestType.Data[1] = 0x0D;
	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	//CAN_Delay10ms(10);
}

void PrechargeM_Change(void)		//继电器切换
{
	PrechargeM_StartMaster();			//闭合总正
	PrechargeM_StopPre();			//断开预充
	//CAN_PreStateOut_TestType.Data[1] = 0x0E;
	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	//CAN_Delay10ms(10);
}

int PrechargeM_IsFail(void)			//超时判断函数
{									//判断自启动预充至此刻的时间是否超过3秒
	if (PreCfg_Clock() <= 3)					//PIT定时器16位通道1每次计数步长为0.3s
	{	
	  //CAN_PreStateOut_TestType.Data[1] = 0x0F;
  	//CAN1_SendMsg(&CAN_PreStateOut_TestType);
	  //CAN_Delay10ms(10);
		return 0;
	}
	else
	{
		return 1;
	}
}

int PrechargeM_IsFinish(void)		//预充完成判断函数
{
	if (Hv_Get(V1) * 100 >= Hv_Get(BAT) * 95)				//判断V1电压是否大于BAT电压的95%
	{
		//CAN_PreStateOut_TestType.Data[1] = 0xAA;
	  //CAN1_SendMsg(&CAN_PreStateOut_TestType);
  	//CAN_Delay10ms(10);
		return 1;
	}
	else
	{
		return 0;
	}
}



