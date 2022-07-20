#include "PrechargeM.h"
#include "Pre_Cfg.h"
#include "CAN_Cfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)			//Ԥ���ʼ������
{
}

void PrechargeM_StartPre(void)		//�պ�Ԥ�俪��
{
	RelayM_Control(PRECHANG ,1);
}

void PrechargeM_StopPre(void)		//�Ͽ�Ԥ�俪��
{
	RelayM_Control(PRECHANG ,0);
}

void PrechargeM_StartMaster(void)	//�պ���������
{
	RelayM_Control(MASTER ,1);
}

void PrechargeM_StopMaster(void)	//�Ͽ���������
{
	RelayM_Control(MASTER ,0);
}

void PrechargeM_Change(void)		//�̵����л�����
{
	PrechargeM_StartMaster();		//�պ�����
	PrechargeM_StopPre();			//�Ͽ�Ԥ��
}

int PrechargeM_IsFail(void)			//��ʱ�жϺ���
{									//�ж�������Ԥ�����˿̵�ʱ���Ƿ񳬹�3��
	int ref;
	if (Pre_Cfg_Clock() <= 3)
	{
		ref = 0;
	}
	else
	{
		ref = 1;
	}
	return ref;
}

int PrechargeM_IsFinish(void)		//Ԥ������жϺ���
{
	int ref;
	if (Hv_Get(V1) * 100 >= Hv_Get(BAT) * 95)	//�ж�V1��ѹ�Ƿ����BAT��ѹ��95%
	{
		ref = 1;
	}
	else
	{
		ref = 0;
	}
	return ref;
}



