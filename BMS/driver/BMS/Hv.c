#include "Hv.h"
#include "Pre_Cfg.h"

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
	else if (object == V1)								//ѡ��V1
	{
		rebuf = Per_Cfg_GetVoltage(V1);	//����V1��ѹ
	}
	else if (object == V2)								//ѡ��V2
	{
		rebuf = Per_Cfg_GetVoltage(V2);	//����V1��ѹ
	}
	else if (object == V3)								//ѡ��V3
	{
		rebuf = Per_Cfg_GetVoltage(V3);	//����V1��ѹ
	}
	else
	{
	}
	return rebuf;
}