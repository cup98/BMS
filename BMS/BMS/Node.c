#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

Node_Num_Type Init_Node = Node0;		//��ʼ���ڵ�״̬
int node_start = 0;

void Node_Init(void)				//Node��ʼ������
{
}

void No_Act(void)					//Node�պ���
{
}

/*void Node_Poll(void)            	//Node�ڵ��жϺ���
{
	unsigned char i = 0, Run_Num = 0;
    for (Run_Num = 0 ;Pre_Cfg_NodeStateType[Init_Node-1][Run_Num].Current_Node ==
    				  Pre_Cfg_NodeStateType[Init_Node-1][0].Current_Node ;Run_Num++)    		//��ȡ��ǰ�ڵ�ķ�֧�����Ա㴫��ڵ�״̬�жϺ���
    {
    }
    CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;     			                        //���ڵ��֧����ŵ�CAN���ݶ�6
	for (i = 0; i < Run_Num; i++)                                                  				//����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
	{
		if (Pre_Cfg_NodeStateType[Init_Node-1][i].Condition() ==
			Pre_Cfg_NodeStateType[Init_Node-1][i].Branch_Condition)                    			//Ѱ�ұ��η�֧������޷���
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (Init_Node-1); 	                        //������ִ�нڵ����CAN���ݶ�0

			Pre_Cfg_NodeStateType[Init_Node-1][i].Action();                                    	//ִ�б��ζ���
			Init_Node = Pre_Cfg_NodeStateType[Init_Node-1][i].Next_Node;              			//���´�ִ�еĽڵ�Ŷ�ȡ����

		  	CAN_CfgPreStateOut_TestType.Data[1] = (Init_Node-1);                          //���´�ִ�нڵ����CAN���ݶ�1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//��CAN������״̬������ͳ���
	    	{
	    	}
			break;
		}
	}
} */

void Node_Poll(void)            	//Node�ڵ��жϺ���
{
	unsigned char i = 0, Run_Num = 0;
	//Run_Num = sizeof(Pre_Cfg_NodeStateType)/sizeof(Pre_Cfg_NodeStateType[0]);//sizeof(Pre_Cfg_NodeStateType[0])
  CAN_CfgPreStateOut_TestType.Data[6] = Run_Num;
  
  /*if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//��CAN������״̬������ͳ���
	{
	} */
  
	for (i = 0; i < 8; i++)                                                  				//����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
	{
		if (Pre_Cfg_NodeStateType[i].Current_Node == Init_Node) 
		{	  
		if (Pre_Cfg_NodeStateType[i].Condition() ==
			Pre_Cfg_NodeStateType[i].Branch_Condition)                    			//Ѱ�ұ��η�֧������޷���
		{
		  	CAN_CfgPreStateOut_TestType.Data[0] = (unsigned char)Init_Node; 	                        //������ִ�нڵ����CAN���ݶ�0

			Pre_Cfg_NodeStateType[i].Action();                                    	//ִ�б��ζ���
			Init_Node = Pre_Cfg_NodeStateType[Init_Node].Next_Node;              			//���´�ִ�еĽڵ�Ŷ�ȡ����

		  	CAN_CfgPreStateOut_TestType.Data[1] = (unsigned char)Init_Node;                          //���´�ִ�нڵ����CAN���ݶ�1
	    	if (CAN1_SendMsg(&CAN_CfgPreStateOut_TestType))										//��CAN������״̬������ͳ���
	    	{
	    	}
			//break;
		}
		}
	}
} 


