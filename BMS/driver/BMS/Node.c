#include "Node.h"
#include "Node_Cfg.h"

static Node_Num_Type NodeInit = NODE_0;//��ʼ���ڵ�״̬
Node_ElementBackType Node_ElementBack;
Node_StateInfoType Node_StateInfo;

void Node_Init(void)                //Node��ʼ������
{
}

void Node_NoAct(void)                   //Node�պ���
{
}

void Node_Poll(void)                //Node�ڵ��жϺ���
{
    unsigned char i = 0 ,branch = 0;

    Node_StateInfo.node = NodeInit;
    Node_StateInfo.state = &(Node_StateCfg[NodeInit]);
    branch = Node_StateInfo.state->num;//��ȡ�ڵ�״̬����

    Node_ElementBack.current_node = NodeInit;
    Node_ElementBack.branch_num = branch;

    for (i = 0; i < branch; i++)                                                             //����֧��ѭ����Ѱ�Ҷ�Ӧ�Ķ�������
    {
        if (Node_StateInfo.state->state[i].branch_condition() //�жϵ�ǰ�ڵ��Ƿ������ڵ���ͬ
            == Node_StateInfo.state->state[i].condition)//�ж�����������֧�����Ƿ���ͬ
        {
            Node_StateInfo.state->state[i].action();//ִ�б��ζ���
            NodeInit = Node_StateInfo.state->state[i].next_node;//���´�ִ�еĽڵ�Ŷ�ȡ����

            Node_ElementBack.next_node = NodeInit;
            break;
        }
    }
}

int Node_StateBack(Node_Element_Type state)                 //Node�պ���
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



