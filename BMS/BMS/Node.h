#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _PreNodeNum_Type
{
    Node0 = 1,
    Node1,
    Node2
} PreNodeNum_Type;

typedef struct _PreNode_Struct_Type        //预充电节点结构
{
    PreNodeNum_Type Node_Num;                          //当前节点号
    int (*Condition)(void);                //条件
    int Branch_Condition;                  //分支条件
    void (*Action)(void);                  //执行动作
    int Next_Node_Num;                     //下个节点号
} PreNode_Struct_Type;



//节点流程控制模块初始化函数
extern void Node_Init(void);
//Node模块执行函数
extern void Node_Poll(void);
//空函数
extern void No_Act(void);

#endif