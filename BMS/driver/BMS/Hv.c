#include "Hv.h"
#include "Pre_Cfg.h"

void Hv_Init(void)                      //��ѹ����ģ���ɳ�ʼ������
{
}

int Hv_Get(Hv_Voltage_Type object)      //��ȡ��ѹ����
{
    int rebuf = 0;
    if(object == HV_BAT)                   //ѡ��Bat
    {
        rebuf = Per_Cfg_GetVoltage(HV_BAT);//����BAT��ѹ
    }
    else if (object == HV_V1)                              //ѡ��V1
    {
        rebuf = Per_Cfg_GetVoltage(HV_V1); //����V1��ѹ
    }
    else if (object == HV_V2)                              //ѡ��V2
    {
        rebuf = Per_Cfg_GetVoltage(HV_V2); //����V1��ѹ
    }
    else if (object == HV_V3)                              //ѡ��V3
    {
        rebuf = Per_Cfg_GetVoltage(HV_V3); //����V1��ѹ
    }
    else
    {
    }
    return rebuf;
}