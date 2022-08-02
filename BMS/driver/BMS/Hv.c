#include "Hv.h"
#include "Hv_LCfg.h"
#include "Pre_LCfg.h"

void Hv_Init(void)                      //��ѹ����ģ���ɳ�ʼ������
{
}

void Hv_InterruptON(void)               //�жϿ�
{
}

void Hv_InterruptOFF(void)              //�жϹ�
{
}

int Hv_RangeOut(uint32 data ,Hv_AttributeType attribute)    //��������Ƿ���Ԥ��Ĳ������䣬����������ֵ����������
{
    int rebuf;
    uint32 max ,min;
    if (attribute == HV_VOLTAGE)
    {
        min = HV_VOLTAGE_MIN;
        max = HV_VOLTAGE_MAX;
    }
    else if (attribute == HV_CURRENT)
    {
        min = HV_CURRENT_MIN;
        max = HV_CURRENT_MAX;
    }
    else if (attribute == HV_TEMP)
    {
        min = HV_TEMP_MIN;
        max = HV_TEMP_MAX;
    }
    else
    {
    }

    if (data > min && data < max)
    {
        rebuf = TRUE;
    }
    else
    {
        rebuf = FALSE;
    }
    return rebuf;
}

Hv_AttributeType Hv_BatteryStats(uint8 channel)     //����Ŀ��ĳ�ŵ�״̬
{
    Hv_AttributeType rebuf;
    if (HV_CURRENT_(channel) > 0)
    {
        rebuf = HV_DISCHARGE;
    }
    else
    {
        rebuf = HV_CHARGE;
    }
    return rebuf;
}

uint32 Hv_GetAttribute(uint8 channel ,Hv_AttributeType attribute)   //��ȡĿ�����Ե�����
{
    uint32 rebuf;
    switch (attribute)
    {
        case HV_VOLTAGE:
        {
            rebuf = HV_VOLTAGE_(channel);
        } break;

        case HV_CURRENT:
        {
            rebuf = HV_VOLTAGE_(channel);
        } break;

        case HV_TEMP:
        {
            rebuf = HV_VOLTAGE_(channel);
        } break;
    }
    return rebuf;
}

uint32 Hv_Get(uint8 channel ,Hv_AttributeType attribute)        //��ȡĿ����������
{
    uint32 rebuf;
    rebuf = Hv_GetAttribute(channel ,attribute);
    if (Hv_RangeOut(rebuf ,attribute) == FALSE)                         //��������Ƿ�����Ч���䣬�������»�ȡ����
    {
        rebuf = Hv_GetAttribute(channel ,attribute);
    }
    return rebuf;
}


