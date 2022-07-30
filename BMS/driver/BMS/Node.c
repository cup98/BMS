#include "Node.h"
#include "Node_LCfg.h"

void Node_Init(void)                                     //Node��ʼ������
{
}

void Node_NoAct(void)                                    //Node�պ���
{
}

void Node_InterruptON(void)
{
}

void Node_InterruptOFF(void)
{
}

void Node_Poll(void)                                     //Node�ڵ��жϺ���
{
    static Node_Num_Type NodeInit = (Node_Num_Type)NODE_0;              //��ʼ���ڵ�״̬
    static Node_StateType Node_Data;
    unsigned char i = 0 ,condition = 0;

    Node_InterruptOFF();
    Node_Data.node = NodeInit;                      //��ȡ��ǰ�ڵ��
    Node_Data.state = &(Node_StateCfg[NodeInit]);   //��ȡ��ǰ�ڵ�״̬
    condition = Node_Data.state->num;                  //��ȡ�ڵ�״̬����
    Node_ElementBack.current_node = NodeInit;            //�����ǰ�ڵ��
    Node_ElementBack.condition_num = condition;                //�����ǰ�ڵ��֧��
    Node_InterruptON();
    for (i = 0; i < condition; i++)                         //����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
    {
        if (i < condition)                                  //����Խ�籣��
        {
            if (Node_Data.state->state[i].condition()       //�жϵ�ǰ�ڵ��Ƿ������ڵ���ͬ
                == Node_Data.state->state[i].accord)            //�ж�����������֧�����Ƿ���ͬ
            {
                Node_Data.state->state[i].action();                //ִ�б��ζ���

                Node_InterruptOFF();
                NodeInit = Node_Data.state->state[i].next_node;    //����´νڵ��
                Node_ElementBack.next_node = NodeInit;
                Node_InterruptON();
                break;
            }
        }
    }
}

int Node_StateBack(Node_Element_Type state)                         //�ڵ�״̬��Ϣ��ȡ����
{
    int rebuf;
    if (state == NODE_Element_CURRENT_STATE)
    {
        rebuf = Node_ElementBack.current_node;
    }
    else if (state == NODE_Element_NEXT_STATE)
    {
        rebuf = Node_ElementBack.next_node;
    }
    else if (state == NODE_Element_CONDITION_NUM)
    {
        rebuf = Node_ElementBack.condition_num;
    }
    else
    {
    }
    return rebuf;
}



