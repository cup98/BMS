#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

Node_Num_Type Init_Node = Node0;	//��ʼ���ڵ�״̬
int node_start = 0;

void Node_Init(void)				//Node��ʼ������
{
}

void No_Act(void)					//Node�պ���
{
}

void Node_Poll(void)            	//Node�ڵ��жϺ���
{
	unsigned char i = 0;
  	CAN_CfgPreStateOut_TestType.Data[7] = Node_Num;												 //��ȡ�ڵ�״̬����
	for (i = 0; i < Node_Num; i++)                                                  			 //����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
	{
		CAN_CfgPreStateOut_TestType.Data[6] = i;
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
		}
	}
}


