#ifndef __PRE_LCFG_H
#define __PRE_LCFG_H

#include "STD.h"

typedef enum _Pre_State_Type        //����Ԥ����������
{
    PRE_CFG_FAULT,                  //�����ж�
    PRE_CFG_CLOCK,                  //Ԥ�䳬ʱ�ж�
    PRE_CFG_VOLTAGE,                //Ԥ���ѹ����
    PRE_CFG_PERCENT,
} Pre_State_Type;

typedef struct _Pre_CfgStateType    //����Ԥ�����ô洢�ṹ��
{
    unsigned int fault;            //�������
    unsigned int clock;            //����ʱ��
    unsigned int pre_voltage;      //�����ѹ
    unsigned int percent;
} Pre_CfgStateType;

typedef struct _Pre_Cfg_TimeOutType  //����Ԥ�䳬ʱ��ֹʱ��ṹ��
{
    int second;
} Pre_Cfg_TimeOutType;

typedef struct _Pre_Cfg_VoltageStdType  //�����ڵ�״̬���ṹ��
{
    uint8 channel;
    int percent;
} Pre_Cfg_VoltageStdType;

extern Pre_CfgStateType Pre_CfgState;
extern Pre_Cfg_TimeOutType Pre_Cfg_TimeOut;
extern Pre_Cfg_VoltageStdType Pre_Cfg_VoltageStd;
extern void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned int data); //�����ݴ�����Ӧ�����ýṹ���ڣ�Ŀ�꣬���ݣ�
extern int Pre_Cfg_Fault(void);                                         //��ȡ�����������أ�0�޴�1�д�
extern int Pre_Cfg_Clock(void);                                         //��ȡԤ��ȴ�ʱ�亯�������أ���λ�룬С��3��
extern int Per_Cfg_GetVoltage(uint8 channel);                  //��ȡĿ���ѹ(Ŀ��)�����أ���ѹֵ

#endif