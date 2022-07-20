#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

void Hv_Init(void)						//��ѹ����ģ���ɳ�ʼ������
{
}

int Hv_Get(Hv_Voltage_Type object)		//��ȡ��ѹ����
{
	int ref = 0;
	if(object == BAT)					//ѡ��Bat
	{
		ref = Per_Cfg_GetVoltage(BAT);	//����BAT��ѹ
	}
	else								//ѡ��V1
	{
		ref = Per_Cfg_GetVoltage(V1);	//����V1��ѹ
	}
	return ref;
}