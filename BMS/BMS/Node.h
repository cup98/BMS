#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_NumType
{
    Node0,
    Node1,
    Node2
} Node_NumType;

typedef struct _Node_StateType        //预充电节点结构
{
    Node_NumType Node_Num;                          //当前节点号
    int (*Condition)(void);                //条件
    int Branch_Condition;                  //分支条件
    void (*Action)(void);                  //执行动作
    Node_NumType Next_Node_Num;                     //下个节点号
} Node_StateType;



//节点流程控制模块初始化函数
extern void Node_Init(void);
//Node模块执行函数
extern void Node_Poll(void);
//空函数
extern void No_Act(void);

#endif