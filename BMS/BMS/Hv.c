#include "Hv.h"
#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

void Hv_Init(void)						//��ѹ����ģ���ɳ�ʼ������
{
}

int Hv_Get(Hv_Voltage_Type object)		//��ȡ��ѹ����
{
	int rebuf = 0;
	if(object == BAT)					//ѡ��Bat
	{
		rebuf = Per_Cfg_GetVoltage(BAT);//����BAT��ѹ
	}
	else								//ѡ��V1
	{
		rebuf = Per_Cfg_GetVoltage(V1);	//����V1��ѹ
	}
	return rebuf;
}