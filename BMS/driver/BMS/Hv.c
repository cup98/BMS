#include "Hv.h"
#include "Hv_LCfg.h"
#include "Pre_LCfg.h"

void Hv_Init(void)                      //高压管理模块由初始化函数
{
}

void Hv_InterruptON(void)               //中断开
{
}

void Hv_InterruptOFF(void)              //中断关
{
}

int Hv_RangeOut(uint32 data ,Hv_AttributeType attribute)    //检测数据是否在预设的测量区间，输入数据数值和数据属性
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

Hv_AttributeType Hv_BatteryStats(uint8 channel)     //返回目标的充放电状态
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

uint32 Hv_GetAttribute(uint8 channel ,Hv_AttributeType attribute)   //获取目标属性的数据
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

uint32 Hv_Get(uint8 channel ,Hv_AttributeType attribute)        //获取目标属性数据
{
    uint32 rebuf;
    rebuf = Hv_GetAttribute(channel ,attribute);
    if (Hv_RangeOut(rebuf ,attribute) == FALSE)                         //检测数据是否在有效区间，否在重新获取数据
    {
        rebuf = Hv_GetAttribute(channel ,attribute);
    }
    return rebuf;
}


