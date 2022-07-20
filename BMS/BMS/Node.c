#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

Node_Num_Type Init_Node = Node0;		//初始化节点状态
int node_start = 0;

void Node_Init(void)				//Node初始化函数
{
}

void No_Act(void)					//Node空函数
{
}

/*void Node_Poll(void)            	//Node节点判断函数
{
	unsigned char i = 0, Run_Num = 0;
    for (Run_Num = 0 ;Pre_Cfg_NodeStateType[Init_Node-1][Run_Num].Current_Node ==
    				  Pre_Cfg_NodeStateType[Init_Node-1][0].Current_Node ;Run_Num++)    		//读取当前节点的分支数，以便传入节点状态判断函数
    {
    }
    CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;     			                        //将节点分支数存放到CAN数据段6
	for (i = 0; i < Run_Num; i++)                                                  				//做分支内循环，寻找对应的动作函数
	{
		if (Pre_Cfg_NodeStateType[Init_Node-1][i].Condition() ==
			Pre_Cfg_NodeStateType[Init_Node-1][i].Branch_Condition)                    			//寻找本次分支情况有无符合
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (Init_Node-1); 	                        //将本次执行节点存在CAN数据段0

			Pre_Cfg_NodeStateType[Init_Node-1][i].Action();                                    	//执行本次动作
			Init_Node = Pre_Cfg_NodeStateType[Init_Node-1][i].Next_Node;              			//将下次执行的节点号读取出来

		  	CAN_CfgPreStateOut_TestType.Data[1] = (Init_Node-1);                          //将下次执行节点存在CAN数据段1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//用CAN将本次状态情况发送出来
	    	{
	    	}
			break;
		}
	}
} */

void Node_Poll(void)            	//Node节点判断函数
{
	unsigned char i = 0, Run_Num = 0;
	//Run_Num = sizeof(Pre_Cfg_NodeStateType)/sizeof(Pre_Cfg_NodeStateType[0]);//sizeof(Pre_Cfg_NodeStateType[0])
  CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;
  
  /*if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//用CAN将本次状态情况发送出来
	{
	} */
  
	for (i = 0; i < 8; i++)                                                  				//做分支内循环，寻找对应的动作函数
	{
		if (Pre_Cfg_NodeStateType[i].Current_Node == Init_Node) 
		{	  
		if (Pre_Cfg_NodeStateType[i].Condition() ==
			Pre_Cfg_NodeStateType[i].Branch_Condition)                    			//寻找本次分支情况有无符合
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (unsigned char)Init_Node; 	                        //将本次执行节点存在CAN数据段0

			Pre_Cfg_NodeStateType[i].Action();                                    	//执行本次动作
			Init_Node = Pre_Cfg_NodeStateType[Init_Node].Next_Node;              			//将下次执行的节点号读取出来

		  	CAN_CfgPreStateOut_TestType.Data[1] = (unsigned char)Init_Node;                          //将下次执行节点存在CAN数据段1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//用CAN将本次状态情况发送出来
	    	{
	    	}
			//break;
		}
		}
	}
} 


