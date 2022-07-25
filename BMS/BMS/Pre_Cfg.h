#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

typedef struct _Pre_Cfg_IsFailType  //�����ڵ�״̬���ṹ��
{
    int second;
} Pre_Cfg_IsFailType;

typedef struct _Pre_Cfg_IsFinishType  //�����ڵ�״̬���ṹ��
{
    Hv_Voltage_Type object; //��ǰ�ڵ�
    int percent;
} Pre_Cfg_IsFinishType;

extern int Pre_Cfg_Fault(void);							//���ô�����:0�޴�,1�д�
extern int Pre_Cfg_Clock(void);							//����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//��ȡĿ���ѹ(Ŀ��BAT/V1)
extern Pre_Cfg_IsFailType pre_cfg_max_time;
extern Pre_Cfg_IsFinishType pre_cfg_voltage_stats;


#endif