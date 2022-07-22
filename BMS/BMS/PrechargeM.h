#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef enum _PrechargeM_Voltage_Type 				//��ȡ��ѹĿ��
{
	BAT,
	V1,
	V2,
	V3,
} PrechargeM_Voltage_Type;

extern void PrechargeM_Init(void);			//��ʼ������
extern void PrechargeM_StartPre(void);		//����Ԥ�亯��,�պ�Ԥ�俪��
extern void PrechargeM_StopPre(void);		//ֹͣԤ�亯��,�ο�Ԥ�俪��
extern void PrechargeM_StartMaster(void);	//�պ���������
extern void PrechargeM_StopMaster(void);	//�Ͽ���������
extern void PrechargeM_Change(int max_time);		//�̵����л�����,�պ��������Ͽ�Ԥ��
extern int PrechargeM_IsFinish(PrechargeM_Voltage_Type object ,int finish_ratio);		//Ԥ������жϺ���,�ж�V1��ѹ�Ƿ����BAT��ѹ��95%
extern int PrechargeM_IsFail(void);			//��ʱ�жϺ���,�ж�������Ԥ�����˿̵�ʱ���Ƿ񳬹�3��
#endif