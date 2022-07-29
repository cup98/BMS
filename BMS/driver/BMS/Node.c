#include "Node.h"
#include "Node_Cfg.h"


void Node_Init(void)                                     //Node初始化函数
{
}

void Node_NoAct(void)                                    //Node空函数
{
}

void Node_Poll(Node_State_InfoType *Node_Info)                                     //Node节点判断函数
{
    static Node_Num_Type node_init = NODE_0;              //初始化节点状态
    unsigned char i = 0 ,branch = 0;

    Node_Info->node = node_init;                      //获取当前节点号
    Node_Info->state = &(Node_StateCfg[node_init]);   //获取当前节点状态
    branch = Node_Info->state->num;                  //获取节点状态数量

    Node_ElementBack.current_node = node_init;            //输出当前节点号
    Node_ElementBack.branch_num = branch;                //输出当前节点分支数

    for (i = 0; i < branch; i++)                         //做分支内循环，寻找对应的动作函数
    {
        if (Node_Info->state->state[i].branch_condition()       //判断当前节点是否与进入节点相同
            == Node_Info->state->state[i].condition)            //判断条件与进入分支条件是否相同
        {
            Node_Info->state->state[i].action();                //执行本次动作
            node_init = Node_Info->state->state[i].next_node;    //输出下次节点号

            Node_ElementBack.next_node = node_init;
            break;
        }
    }
}

int Node_StateBack(Node_Element_Type state)                         //节点状态信息读取函数
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



