#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

extern void PrechargeM_Init();			//��ʼ������
extern void PrechargeM_StartPre();		//����Ԥ�亯��,�պ�Ԥ�俪��
extern void PrechargeM_StopPre();		//ֹͣԤ�亯��,�ο�Ԥ�俪��
extern void PrechargeM_StartMaster();	//�պ���������
extern void PrechargeM_StopMaster();	//�Ͽ���������
extern void PrechargeM_Change();		//�̵����л�����,�պ��������Ͽ�Ԥ��
extern int PrechargeM_IsFinish();		//Ԥ������жϺ���,�ж�V1��ѹ�Ƿ����BAT��ѹ��95%
extern int PrechargeM_IsFail();			//��ʱ�жϺ���,�ж�������Ԥ�����˿̵�ʱ���Ƿ񳬹�3��
#endif