#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type     //�оٽڵ���������
{
    NODE0,                      //�жϹ��Ͻڵ�
    NODE1,                      //Ԥ������жϽڵ�
    NODE2,                      //�ŵ�����жϽڵ�
} Node_Num_Type;

typedef struct _Node_StateType  //�����ڵ�״̬���ṹ��
{
    Node_Num_Type current_node; //��ǰ�ڵ�
    int (*branch_condition)(void);     //����
    int condition;       //��֧����
    void (*action)(void);       //����
    Node_Num_Type next_node;    //��һ�ڵ�
} Node_StateType;

extern void Node_Init(void);    //Node��ʼ������
extern void Node_NoAct(void);       //Node�պ���
extern void Node_Poll(void);    //Node�ڵ��жϺ���

#endif