#include "Node.h"
#include "Node_LCfg.h"

void Node_Init(void)                                     //Node初始化函数
{
}

void Node_NoAct(void)                                    //Node空函数
{
}

void Node_InterruptON(void)
{
}

void Node_InterruptOFF(void)
{
}

void Node_Poll(void)                                     //Node节点判断函数
{
    static Node_Num_Type NodeInit = (Node_Num_Type)NODE_0;              //初始化节点状态
    static Node_StateType Node_Data;
    unsigned char i = 0 ,condition = 0;

    Node_InterruptOFF();
    Node_Data.node = NodeInit;                      //获取当前节点号
    Node_Data.state = &(Node_StateCfg[NodeInit]);   //获取当前节点状态
    condition = Node_Data.state->num;                  //获取节点状态数量
    Node_ElementBack.current_node = NodeInit;            //输出当前节点号
    Node_ElementBack.condition_num = condition;                //输出当前节点分支数
    Node_InterruptON();
    for (i = 0; i < condition; i++)                         //做分支内循环，寻找对应的动作函数
    {
        if (i < condition)                                  //数组越界保护
        {
            if (Node_Data.state->state[i].condition()       //判断当前节点是否与进入节点相同
                == Node_Data.state->state[i].accord)            //判断条件与进入分支条件是否相同
            {
                Node_Data.state->state[i].action();                //执行本次动作

                Node_InterruptOFF();
                NodeInit = Node_Data.state->state[i].next_node;    //输出下次节点号
                Node_ElementBack.next_node = NodeInit;
                Node_InterruptON();
                break;
            }
        }
    }
}

int Node_StateBack(Node_Element_Type state)                         //节点状态信息读取函数
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



