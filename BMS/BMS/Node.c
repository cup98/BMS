#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "Node_Cfg.h"

Node_Num_Type node_init = NODE0;
//Node_StateInfoType state_init.node = node_init; //��ʼ���ڵ�״̬

void Node_Init(void)				//Node��ʼ������
{
}

void Node_NoAct(void)					//Node�պ���
{
}

void Node_Poll(void)            	//Node�ڵ��жϺ���
{
	unsigned char i = 0,branch = 0;
  	//CAN_CfgPreStateOut_TestType.Data[7] = Node_Num;												 //��ȡ�ڵ�״̬����
	//state_init->state = Node_StateCfg[node_init];
	node_state_info.node = node_init;
	node_state_info.state = &(node_state_cfg[node_init]);
 	branch = node_state_info.state->num;

	CAN_GetToMsg_data(7 ,branch);
	CAN_GetToMsg_data(0 ,node_init);
	//Node_StateCfg[Init_Node].state
	for (i = 0; i < branch; i++)                                                  			 //����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
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
		if ((Pre_Cfg_NodeStateType[i].Current_Node == Init_Node) &&								 //�жϵ�ǰ�ڵ��Ƿ������ڵ���ͬ
		    (Pre_Cfg_NodeStateType[i].Condition()  == Pre_Cfg_NodeStateType[i].Branch_Condition))//�ж�����������֧�����Ƿ���ͬ
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (unsigned char)Init_Node; 	                 //������ִ�нڵ����CAN���ݶ�0

			Pre_Cfg_NodeStateType[i].Action();                                    				 //ִ�б��ζ���
			Init_Node = Pre_Cfg_NodeStateType[i].Next_Node;              						 //���´�ִ�еĽڵ�Ŷ�ȡ����

		  	CAN_CfgPreStateOut_TestType.Data[1] = (unsigned char)Init_Node;                      //���´�ִ�нڵ����CAN���ݶ�1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										 //��CAN������״̬������ͳ���
	    	{
	    	}
	    	break;
		}*/
	}
}


