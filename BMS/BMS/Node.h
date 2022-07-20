#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type      //列举节点数量名称
{
    Node0 = 1,                  //判断故障节点
    Node1 = 2,                  //预充完成判断节点
    Node2 = 3,                  //放电故障判断节点
} Node_NumType;


typedef struct _Node_StateType  //构建节点状态机结构体
{
    Node_NumType Current_Node;  //当前节点
    int (*Condition)(void);     //条件
    int Branch_Condition;       //分支条件
    void (*Action)(void);       //动作
    Node_NumType Next_Node;     //下一节点
} Node_StateType;


extern void Node_Init(void);    //Node初始化函数
extern void Node_Poll(void);    //Node节点判断函数
extern void No_Act(void);       //Node空函数

#endif