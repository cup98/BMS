#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

Node_NumType Init_Node = Node0;									//设置节点标志位初始为1

void Node_Init(void)								//Node模块初始化
{

}

void No_Act(void)									//Node模块执行空函数
{

}

void Node_Poll(void)
{
	int i,Run_Num;

    for (Run_Num = 1 ;Pre_Cfg_NodeStateTransition_TableType[Init_Node][Run_Num].Node_Num
    	 == Pre_Cfg_NodeStateTransition_TableType[Init_Node][0].Node_Num ;Run_Num++)
    {
    }
    CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;
	for (i = 0; i < Run_Num; i++)
	{
		if (Pre_Cfg_NodeStateTransition_TableType[Init_Node][i].Condition() ==
			Pre_Cfg_NodeStateTransition_TableType[Init_Node][i].Branch_Condition)
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = Init_Node;

			Pre_Cfg_NodeStateTransition_TableType[Init_Node][i].Action();
			Init_Node = Pre_Cfg_NodeStateTransition_TableType[Init_Node][i].Next_Node_Num;

		  	CAN_CfgPreStateOut_TestType.Data[1] = Init_Node;
	    	CAN1_SendMsg(&CAN_CfgPreStateOut_TestType);
			break;
		}
	}
}

