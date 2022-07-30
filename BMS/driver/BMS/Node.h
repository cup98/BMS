#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Node_Num_Type         //�оٽڵ���������
{
    NODE_0,
    NODE_1,
    NODE_2,
} Node_Num_Type;

typedef enum _Node_Element_Type     //�оٽڵ�״̬
{
    NODE_Element_CURRENT_STATE,
    NODE_Element_NEXT_STATE,
    NODE_Element_CONDITION_NUM,
} Node_Element_Type;

typedef struct _Node_StateInfoType      //�����ڵ�״̬���ṹ��
{
    Node_Num_Type current_node;     //��ǰ�ڵ�
    int (*condition)(void);         //��֧����
    int accord;                     //����
    void (*action)(void);           //����
    Node_Num_Type next_node;        //��һ�ڵ�
} Node_StateInfoType;

typedef struct _Node_StateCfgType   //�ڵ�״̬����
{
    unsigned char num;
    const Node_StateInfoType* state;
} Node_StateCfgType;

typedef struct _Node_State_InfoType  //�ڵ�״̬��Ϣ
{
    Node_Num_Type node;
    const Node_StateCfgType* state;
} Node_StateType;

typedef struct _Node_ElementBackType//��������ڵ���Ϣ�ṹ��
{
    Node_Num_Type current_node;
    int next_node;
    int condition_num;
} Node_ElementBackType;

extern void Node_Init(void);        //Node��ʼ������
extern void Node_NoAct(void);       //Node�պ���
extern void Node_Poll(void);        //Node�ڵ��жϺ���
extern void Node_InterruptON(void);
extern void Node_InterruptOFF(void);
extern int Node_StateBack(Node_Element_Type state);//�ڵ�״̬���غ���(�ڵ�״̬)�����ؽڵ�״̬��Ӧ����


#endif