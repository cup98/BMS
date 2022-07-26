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

typedef enum _Node_StateSave_Type     //�оٽڵ���������
{
    CURRENT_NODE,                      //�жϹ��Ͻڵ�
    NEXT_NODE,                    //Ԥ������жϽڵ�
    BRANCH_NUM,                      //�ŵ�����жϽڵ�
} Node_StateSave_Type;

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
  Node_StateType *state;
} Node_StateCfgType;

typedef struct _Node_StateInfoType
{
  Node_Num_Type node;
  Node_StateCfgType *state;
} Node_StateInfoType;

typedef struct _Node_BackStateInfoType  //�����ڵ�״̬���ṹ��
{
    int current_node; //��ǰ�ڵ�
    int next_node;    //��һ�ڵ�
    int branch_num;
} Node_BackStateInfoType;

extern void Node_Init(void);    //Node��ʼ������
extern void Node_NoAct(void);       //Node�պ���
extern void Node_Poll(void);    //Node�ڵ��жϺ���
extern int Node_BackNodeState(Node_StateSave_Type state);
extern Node_StateInfoType Node_StateInfo;
extern Node_BackStateInfoType Node_BackStateInfo;


#endif