#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type     //列举节点数量名称
{
    NODE0,                      //判断故障节点
    NODE1,                      //预充完成判断节点
    NODE2,                      //放电故障判断节点
} Node_Num_Type;

typedef struct _Node_StateType  //构建节点状态机结构体
{
    Node_Num_Type current_node; //当前节点
    int (*branch_condition)(void);     //条件
    int condition;       //分支条件
    void (*action)(void);       //动作
    Node_Num_Type next_node;    //下一节点
} Node_StateType;

extern void Node_Init(void);    //Node初始化函数
extern void Node_NoAct(void);       //Node空函数
extern void Node_Poll(void);    //Node节点判断函数

#endif