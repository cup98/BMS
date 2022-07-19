#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

int Init_Node = 0;									//设置节点标志位初始为1
PreNode_Struct_Type Node_StateTransition_Table[3][4] =
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

void Node_Init(void)								//Node模块初始化
{

}

void No_Act(void)									//Node模块执行空函数
{

}

void Node_Poll(void)
{
	int i,Run_Num;

    for (Run_Num = 0 ;Node_StateTransition_Table[Init_Node][Run_Num].Node_Num
    	 == Node_StateTransition_Table[Init_Node][0].Node_Num ;Run_Num++)
    {
    }
    CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;
	for (i = 0; i < Run_Num; i++)
	{
		if (Node_StateTransition_Table[Init_Node][i].Condition() ==
			Node_StateTransition_Table[Init_Node][i].Branch_Condition)
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = Init_Node;

			Node_StateTransition_Table[Init_Node][i].Action();
			Init_Node = Node_StateTransition_Table[Init_Node][i].Next_Node_Num;

		  	CAN_CfgPreStateOut_TestType.Data[1] = Init_Node;
	    	CAN1_SendMsg(&CAN_CfgPreStateOut_TestType);
			break;
		}
	}
}

