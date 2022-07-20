#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type      //�оٽڵ���������
{
    Node0 = 1,                  //�жϹ��Ͻڵ�
    Node1 = 2,                  //Ԥ������жϽڵ�
    Node2 = 3,                  //�ŵ�����жϽڵ�
} Node_NumType;


typedef struct _Node_StateType  //�����ڵ�״̬���ṹ��
{
    Node_NumType Current_Node;  //��ǰ�ڵ�
    int (*Condition)(void);     //����
    int Branch_Condition;       //��֧����
    void (*Action)(void);       //����
    Node_NumType Next_Node;     //��һ�ڵ�
} Node_StateType;


extern void Node_Init(void);    //Node��ʼ������
extern void Node_Poll(void);    //Node�ڵ��жϺ���
extern void No_Act(void);       //Node�պ���

#endif