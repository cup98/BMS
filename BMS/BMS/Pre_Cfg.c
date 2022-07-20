#include "Pre_Cfg.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

int Pre_Cfg_Fault(void)
{
	return CAN1_GetBufType.Data[0];										//举例故障为无:0
}

int Pre_Cfg_Clock(void)
{
	return CAN1_GetBufType.Data[1];
}

Pre_Cfg_GetHvVoltageType Per_Cfg_GetVoltageType =					//举例电压值
{
	100,							//BAT电压为90.0V
	100,							//V1电压为91.0V
};

Node_StateType Pre_Cfg_NodeStateTransition_TableType[3][4] =
{
 	{
 		{Node0 ,Pre_Cfg_Fault ,1 ,No_Act ,Node0 },
 		{Node0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,Node1 },
 	},

 	{
 		{Node1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,Node0 },
 		{Node1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,Node0 },
 		{Node1 ,PrechargeM_IsFinish ,1 ,PrechargeM_Change ,Node2 },
 		{Node1 ,PrechargeM_IsFinish ,0 ,No_Act ,Node1 },
 	},

 	{
 		{Node2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,Node0 },
 		{Node2 ,Pre_Cfg_Fault ,0 ,No_Act ,Node2 },
 	}
};



