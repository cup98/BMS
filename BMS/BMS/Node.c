#include "Node.h"
#include "PreCfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

int Init_Node = 0;									//设置节点标志位初始为1

 PreNode_Struct_Type Node_StateTransition_Table[3][4] =
 {
 	{
 		{0 ,PreCfg_Fault ,2 ,1 ,No_Act ,0 },
 		{0 ,PreCfg_Fault ,2 ,0 ,PrechargeM_StartPre ,1 },
 	},

 	{
 		{1 ,PreCfg_Fault ,4 ,1 ,PrechargeM_StopPre ,0 },
 		{1 ,PrechargeM_IsFail ,4 ,1 ,PrechargeM_StopPre ,0 },
 		{1 ,PrechargeM_IsFinish ,4 ,1 ,PrechargeM_Change ,2 },
 		{1 ,PrechargeM_IsFinish ,4 ,0 ,No_Act ,1 },
 	},

 	{
 		{2 ,PreCfg_Fault ,2 ,1 ,PrechargeM_StopMaster ,0 },
 		{2 ,PreCfg_Fault ,2 ,0 ,No_Act ,2 },
 	}
 };

void Node_Init(void)								//Node模块初始化
{

}

void No_Act(void)									//Node模块执行空函数
{

}

void Node_Poll(void)
{
	int i = 0;
	int Run_Num = Node_StateTransition_Table[Init_Node][0].Branch_Num;
	for (i = 0; i < Run_Num; i++)
	{
		if (Node_StateTransition_Table[Init_Node][i].Condition() ==
			Node_StateTransition_Table[Init_Node][i].Branch_Condition)
		{		
		  CAN_PreStateOut_TestType.Data[0] = Init_Node;
	    CAN1_SendMsg(&CAN_PreStateOut_TestType);
	    
			Node_StateTransition_Table[Init_Node][i].Action();
			Init_Node = Node_StateTransition_Table[Init_Node][i].Next_Node_Num;
			break;
		}
	}
}





















