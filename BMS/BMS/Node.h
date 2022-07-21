#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type     //�оٽڵ���������
{
    Node0,                      //�жϹ��Ͻڵ�
    Node1,                      //Ԥ������жϽڵ�
    Node2,                      //�ŵ�����жϽڵ�
} Node_Num_Type;

typedef struct _Node_StateType  //�����ڵ�״̬���ṹ��
{
    Node_Num_Type Current_Node; //��ǰ�ڵ�
    int (*Condition)(void);     //����
    int Branch_Condition;       //��֧����
    void (*Action)(void);       //����
    Node_Num_Type Next_Node;    //��һ�ڵ�
} Node_StateType;

extern void Node_Init(void);    //Node��ʼ������
extern void No_Act(void);       //Node�պ���
extern void Node_Poll(void);    //Node�ڵ��жϺ���

#endif