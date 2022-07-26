#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

typedef enum _Pre_State_Type     //�оٽڵ���������
{
    FAULT,                      //�жϹ��Ͻڵ�
    CLOCK,                      //Ԥ������жϽڵ�
    PRE_VOLTAGE,                      //�ŵ�����жϽڵ�
} Pre_State_Type;

typedef struct _Pre_CfgStateType  //�����ڵ�״̬���ṹ��
{
    unsigned char fault; //��ǰ�ڵ�
    unsigned char clock;
    unsigned char pre_voltage;
} Pre_CfgStateType;

typedef struct _Pre_Cfg_IsFailType  //�����ڵ�״̬���ṹ��
{
    int second;
} Pre_Cfg_IsFailType;

typedef struct _Pre_Cfg_IsFinishType  //�����ڵ�״̬���ṹ��
{
    Hv_Voltage_Type object; //��ǰ�ڵ�
    int percent;
} Pre_Cfg_IsFinishType;

extern void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned char data);
extern int Pre_Cfg_Fault(void);							//���ô�����:0�޴�,1�д�
extern int Pre_Cfg_Clock(void);							//����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//��ȡĿ���ѹ(Ŀ��BAT/V1)
extern Pre_Cfg_IsFailType Pre_Cfg_MaxTime;
extern Pre_Cfg_IsFinishType Pre_Cfg_VoltageStats;
extern Pre_CfgStateType Pre_CfgState;

#endif