#include "Node.h"
#include "Node_Cfg.h"


void Node_Init(void)                                     //Node��ʼ������
{
}

void Node_NoAct(void)                                    //Node�պ���
{
}

void Node_Poll(Node_State_InfoType *Node_Info)                                     //Node�ڵ��жϺ���
{
    static Node_Num_Type node_init = NODE_0;              //��ʼ���ڵ�״̬
    unsigned char i = 0 ,branch = 0;

    Node_Info->node = node_init;                      //��ȡ��ǰ�ڵ��
    Node_Info->state = &(Node_StateCfg[node_init]);   //��ȡ��ǰ�ڵ�״̬
    branch = Node_Info->state->num;                  //��ȡ�ڵ�״̬����

    Node_ElementBack.current_node = node_init;            //�����ǰ�ڵ��
    Node_ElementBack.branch_num = branch;                //�����ǰ�ڵ��֧��

    for (i = 0; i < branch; i++)                         //����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
    {
        if (Node_Info->state->state[i].branch_condition()       //�жϵ�ǰ�ڵ��Ƿ������ڵ���ͬ
            == Node_Info->state->state[i].condition)            //�ж�����������֧�����Ƿ���ͬ
        {
            Node_Info->state->state[i].action();                //ִ�б��ζ���
            node_init = Node_Info->state->state[i].next_node;    //����´νڵ��

            Node_ElementBack.next_node = node_init;
            break;
        }
    }
}

int Node_StateBack(Node_Element_Type state)                         //�ڵ�״̬��Ϣ��ȡ����
{
    int rebuf;
    if (state == NODE_CURRENT_STATE)
    {
        rebuf = Node_ElementBack.current_node;
    }
    else if (state == NODE_NEXT_STATE)
    {
        rebuf = Node_ElementBack.next_node;
    }
    else if (state == NODE_BRANCH_NUM)
    {
        rebuf = Node_ElementBack.branch_num;
    }
    else
    {
    }
    return rebuf;
}



