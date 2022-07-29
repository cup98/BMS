#include "Hv.h"
#include "Pre_Cfg.h"

/*

int Hv_Get(Hv_Voltage_Type object)      //获取电压函数
{
    int rebuf = 0;
    if(object == HV_BAT)                   //选中Bat
    {
        rebuf = Per_Cfg_GetVoltage(HV_BAT);//返回BAT电压
    }
    else if (object == HV_V1)                              //选中V1
    {
        rebuf = Per_Cfg_GetVoltage(HV_V1); //返回V1电压
    }
    else if (object == HV_V2)                              //选中V2
    {
        rebuf = Per_Cfg_GetVoltage(HV_V2); //返回V1电压
    }
    else if (object == HV_V3)                              //选中V3
    {
        rebuf = Per_Cfg_GetVoltage(HV_V3); //返回V1电压
    }
    else
    {
    }
    return rebuf;
}*/

//uint8 ErrorFlag = 1;

/*typedef struct _Hv_SaveInfoType
{
    Hv_ChannelType channel;
    Hv_AttributeType attribute;
    uint32 data;
} Hv_SaveInfoType;

Hv_SaveInfoType Hv_SaveInfo;*/

Hv_DataType Hv_DemoData[HV_MAX_MODE_NUM] =
{
    {HV_CHANNEL_0,75,104,90},
    {HV_CHANNEL_1,76,103,89},
    {HV_CHANNEL_2,77,102,88},
    {HV_CHANNEL_3,78,101,87},
    {HV_CHANNEL_4,79,100,86},
    {HV_CHANNEL_5,80, 99,85},
    {HV_CHANNEL_6,81, 98,84},
    {HV_CHANNEL_7,82, 97,83},
};

void Hv_Init(void)                      //高压管理模块由初始化函数
{
}

void Hv_InterruptON()
{
}

void Hv_InterruptOFF()
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
    for (i = 0 ;i < HV_MAX_MODE_NUM ;i++)
    {
        if (object == Hv_DemoData[i].channel)
        {
            if (Hv_DemoData[i].current > 0)
            {
                rebuf = HV_DISCHARGE;
            }
            else 
            {
                rebuf = HV_CHARGE;
            }
            break;
        }
    }
    return rebuf;
}

uint32 Hv_GetAttribute(Hv_ChannelType object ,Hv_AttributeType attribute)
{
    int i = 0;
    uint32 rebuf;
    for (i = 0 ;i < HV_MAX_MODE_NUM ;i++)
    {
        if (object == Hv_DemoData[i].channel)
        {
            Hv_InterruptOFF();
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
            Hv_InterruptON();
            break;
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
        rebuf = Hv_GetAttribute(object ,attribute);
    }
    return rebuf;
}


