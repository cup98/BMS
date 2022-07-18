#include "Node.h"

int Fault()
{
	return 0;										//举例故障为无
}

int Init_Node = 0;									//设置节点标志位初始为1

void Node_Init(void)								//Node模块初始化
{

}

void No_Act(void)									//Node模块执行空函数
{

}

void Node_Poll(void)
{
	int Run_Num = Node_StateTransition_Table[Init_Node][0].Branch_Num;
	for (int i = 0; i < Run_Num; i++)
	{
		if (Node_StateTransition_Table[Init_Node][i].Condition() ==
			Node_StateTransition_Table[Init_Node][i].Branch_Condition)
		{
			Node_StateTransition_Table[Init_Node][i].Action();
			Init_Node = Node_StateTransition_Table[Init_Node][i].Next_Node_Num;
			break;
		}
		else
		{
		}
	}
}