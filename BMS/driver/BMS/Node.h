#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type     //�оٽڵ���������
{
    NODE_0,                      //�жϹ��Ͻڵ�
    NODE_1,                      //Ԥ������жϽڵ�
    NODE_2,                      //�ŵ�����жϽڵ�
} Node_Num_Type;

typedef enum _Node_Element_Type     //�оٽڵ���������
{
    NODE_CURRENT_STATE,                      //�жϹ��Ͻڵ�
    NODE_NEXT_STATE,                    //Ԥ������жϽڵ�
    NODE_BRANCH_NUM,                      //�ŵ�����жϽڵ�
} Node_Element_Type;

typedef struct _Node_StateType  //�����ڵ�״̬���ṹ��
{
    Node_Num_Type current_node; //��ǰ�ڵ�
    int (*branch_condition)(void);     //����
    int condition;       //��֧����
    void (*action)(void);       //����
    Node_Num_Type next_node;    //��һ�ڵ�
} Node_StateType;

typedef struct _Node_StateCfgType
{
    unsigned char num;
    const Node_StateType* state;
} Node_StateCfgType;

typedef struct _Node_StateInfoType
{
    Node_Num_Type node;
    const Node_StateCfgType* state;
} Node_StateInfoType;

typedef struct _Node_ElementBackType  //�����ڵ�״̬���ṹ��
{
    int current_node; //��ǰ�ڵ�
    int next_node;    //��һ�ڵ�
    int branch_num;
} Node_ElementBackType;

extern void Node_Init(void);    //Node��ʼ������
extern void Node_NoAct(void);       //Node�պ���
extern void Node_Poll(void);    //Node�ڵ��жϺ���
extern int Node_StateBack(Node_Element_Type state);
extern Node_StateInfoType Node_StateInfo;
extern Node_ElementBackType Node_ElementBack;


#endif