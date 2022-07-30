#include "Hv.h"
#include "Pre_LCfg.h"
#include "Hv_LCfg.h"

void Hv_Init(void)                      //高压管理模块由初始化函数
{
}

void Hv_InterruptON(void)
{
}

void Hv_InterruptOFF(void)
{
}

int Hv_RangeOut(uint32 data ,Hv_AttributeType attribute)
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

Hv_AttributeType Hv_BatteryStats(Hv_ChannelType object)
{
    Hv_AttributeType rebuf;
    int i = 0;
    for (i = 0 ;i < HV_MAX_NUM ;i++)
    {
        if (i < HV_MAX_NUM)
        {
            if (object == Hv_DemoData[i].channel)
            {
                 Hv_InterruptOFF();
                if (Hv_DemoData[i].current > 0)
                {
                    rebuf = HV_DISCHARGE;
                }
                else
                {
                    rebuf = HV_CHARGE;
                }
                Hv_InterruptON();
                break;
            }
        }
    }
    return rebuf;
}

uint32 Hv_GetAttribute(Hv_ChannelType object ,Hv_AttributeType attribute)
{
    int i = 0;
    uint32 rebuf;
    for (i = 0 ;i < HV_MAX_NUM ;i++)
    {
        if (i < HV_MAX_NUM)
        {
            if (object == Hv_DemoData[i].channel)
            {
                if (attribute == HV_VOLTAGE)
                {
                    rebuf = Hv_DemoData[i].voltage;
                }
                else if (attribute == HV_CURRENT)
                {
                    rebuf = Hv_DemoData[i].current;
                }
                else if (attribute == HV_TEMP)
                {
                    rebuf = Hv_DemoData[i].temp;
                }
                else
                {
                }
                break;
            }
        }
    }
    return rebuf;
}

uint32 Hv_Get(Hv_ChannelType object ,Hv_AttributeType attribute)
{
    uint32 rebuf;
    rebuf = Hv_GetAttribute(object ,attribute);
    if (Hv_RangeOut(rebuf ,attribute) == FALSE)
    {
        Hv_InterruptOFF();
        rebuf = Hv_GetAttribute(object ,attribute);
        Hv_InterruptON();
    }
    return rebuf;
}


