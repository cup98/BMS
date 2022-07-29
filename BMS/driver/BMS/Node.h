#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type         //列举节点数量名称
{
    NODE_0,
    NODE_1,
    NODE_2,
} Node_Num_Type;

typedef enum _Node_Element_Type     //列举节点状态
{
    NODE_CURRENT_STATE,
    NODE_NEXT_STATE,
    NODE_BRANCH_NUM,
} Node_Element_Type;

typedef struct _Node_StateType      //构建节点状态机结构体
{
    Node_Num_Type current_node;     //当前节点
    int (*branch_condition)(void);  //分支条件
    int condition;                  //条件
    void (*action)(void);           //动作
    Node_Num_Type next_node;        //下一节点
} Node_StateType;

typedef struct _Node_StateCfgType   //节点状态配置
{
    unsigned char num;
    const Node_StateType* state;
} Node_StateCfgType;

typedef struct _Node_State_InfoType  //节点状态信息
{
    Node_Num_Type node;
    const Node_StateCfgType* state;
} Node_State_InfoType;

typedef struct _Node_ElementBackType//构建输出节点信息结构体
{
    int current_node;
    int next_node;
    int branch_num;
} Node_ElementBackType;

extern void Node_Init(void);        //Node初始化函数
extern void Node_NoAct(void);       //Node空函数
extern void Node_Poll(void);        //Node节点判断函数
extern int Node_StateBack(Node_Element_Type state);//节点状态返回函数(节点状态)，返回节点状态对应数据


#endif