#include "RelayM.h"
#include "CAN_Cfg.h"

RelayM_CtrlType ReM_Ctl =									//��ʼ���̵���״̬
{
	0,
	0,
};

RelayM_SwitchType ReM_Swi =									//��ʼ������״̬
{
	0,
	0,
};

void RelayM_Init(void)										//�̵���ģ���ɳ�ʼ������
{
}

void RelayM_Control(RelayM_Object_Type object ,int state)	//���Ƽ̵������غ���(����Ŀ��,״̬)
{
	if(object == MASTER)
	{
		ReM_Ctl.Master = state;
	}
	else
	{
		ReM_Ctl.Precharge = state;
	}
}

void RelayM_Change(RelayM_Object_Type object ,int state)	//�л����غ���(����Ŀ��,״̬)
{
	if(object == MASTER)
	{
		ReM_Swi.Master  = state;
	}
	else
	{
		ReM_Swi.Precharge = state;
	}
}
