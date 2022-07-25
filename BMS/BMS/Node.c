#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "Node_Cfg.h"

Node_Num_Type node_init = NODE0;
//Node_StateInfoType state_init.node = node_init; //初始化节点状态

void Node_Init(void)				//Node初始化函数
{
}

void Node_NoAct(void)					//Node空函数
{
}

void Node_Poll(void)            	//Node节点判断函数
{
	unsigned char i = 0,branch = 0;
  	//CAN_CfgPreStateOut_TestType.Data[7] = Node_Num;												 //获取节点状态数量
	//state_init->state = Node_StateCfg[node_init];
	node_state_info.node = node_init;
	node_state_info.state = &(node_state_cfg[node_init]);
 	branch = node_state_info.state->num;

	CAN_GetToMsg_data(7 ,branch);
	CAN_GetToMsg_data(0 ,node_init);
	//Node_StateCfg[Init_Node].state
	for (i = 0; i < branch; i++)                                                  			 //做分支内循环，寻找对应的动作函数
	{
		if (node_state_info.state->state[i].branch_condition() == 
			node_state_info.state->state[i].condition)
		{
			node_state_info.state->state[i].action();
			node_init = node_state_info.state->state[i].next_node;

			CAN_GetToMsg_data(1 ,node_init);

			break; 
		}

		/*CAN_CfgPreStateOut_TestType.Data[6] = i;
		if ((Pre_Cfg_NodeStateType[i].Current_Node == Init_Node) &&								 //判断当前节点是否与进入节点相同
		    (Pre_Cfg_NodeStateType[i].Condition()  == Pre_Cfg_NodeStateType[i].Branch_Condition))//判断条件与进入分支条件是否相同
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (unsigned char)Init_Node; 	                 //将本次执行节点存在CAN数据段0

			Pre_Cfg_NodeStateType[i].Action();                                    				 //执行本次动作
			Init_Node = Pre_Cfg_NodeStateType[i].Next_Node;              						 //将下次执行的节点号读取出来

		  	CAN_CfgPreStateOut_TestType.Data[1] = (unsigned char)Init_Node;                      //将下次执行节点存在CAN数据段1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										 //用CAN将本次状态情况发送出来
	    	{
	    	}
	    	break;
		}*/
	}
}


