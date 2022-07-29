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
    NODE_CURRENT_STATE,
    NODE_NEXT_STATE,
    NODE_BRANCH_NUM,
} Node_Element_Type;

typedef struct _Node_StateType      //�����ڵ�״̬���ṹ��
{
    Node_Num_Type current_node;     //��ǰ�ڵ�
    int (*branch_condition)(void);  //��֧����
    int condition;                  //����
    void (*action)(void);           //����
    Node_Num_Type next_node;        //��һ�ڵ�
} Node_StateType;

typedef struct _Node_StateCfgType   //�ڵ�״̬����
{
    unsigned char num;
    const Node_StateType* state;
} Node_StateCfgType;

typedef struct _Node_State_InfoType  //�ڵ�״̬��Ϣ
{
    Node_Num_Type node;
    const Node_StateCfgType* state;
} Node_State_InfoType;

typedef struct _Node_ElementBackType//��������ڵ���Ϣ�ṹ��
{
    int current_node;
    int next_node;
    int branch_num;
} Node_ElementBackType;

extern void Node_Init(void);        //Node��ʼ������
extern void Node_NoAct(void);       //Node�պ���
extern void Node_Poll(void);        //Node�ڵ��жϺ���
extern int Node_StateBack(Node_Element_Type state);//�ڵ�״̬���غ���(�ڵ�״̬)�����ؽڵ�״̬��Ӧ����


#endif