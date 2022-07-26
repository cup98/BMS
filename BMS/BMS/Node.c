#include "Node.h"
#include "Node_Cfg.h"

static Node_Num_Type NodeInit = NODE0;//初始化节点状态
Node_BackStateInfoType Node_BackStateInfo;
Node_StateInfoType Node_StateInfo;

void Node_Init(void)				//Node初始化函数
{
}

void Node_NoAct(void)					//Node空函数
{
}

void Node_Poll(void)            	//Node节点判断函数
{
	unsigned char i = 0,branch = 0;

	Node_StateInfo.node = NodeInit;
	Node_StateInfo.state = &(Node_StateCfg[NodeInit]);
 	branch = Node_StateInfo.state->num;//获取节点状态数量

	Node_BackStateInfo.current_node = NodeInit;
 	Node_BackStateInfo.branch_num = branch;

	for (i = 0; i < branch; i++)                                                  			 //做分支内循环，寻找对应的动作函数
	{
		if (Node_StateInfo.state->state[i].branch_condition() ==//判断当前节点是否与进入节点相同
			Node_StateInfo.state->state[i].condition)//判断条件与进入分支条件是否相同
		{
			Node_StateInfo.state->state[i].action();//执行本次动作
			NodeInit = Node_StateInfo.state->state[i].next_node;//将下次执行的节点号读取出来

			Node_BackStateInfo.next_node = NodeInit;

			break;
		}
	}
}

int Node_BackNodeState(Node_StateSave_Type state)					//Node空函数
{
	int rebuf;
	if (state == CURRENT_NODE)
	{
		rebuf = Node_BackStateInfo.current_node;
	}
	else if (state == NEXT_NODE)
	{
		rebuf = Node_BackStateInfo.next_node;
	}
	else if (state == BRANCH_NUM)
	{
		rebuf = Node_BackStateInfo.branch_num;
	}
	else
	{
	}
	return rebuf;
}



