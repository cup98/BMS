#include "Pre_Cfg.h"

Pre_CfgStateType Pre_CfgState;

Pre_Cfg_IsFailType Pre_Cfg_MaxTime =
{
    3,
};

Pre_Cfg_IsFinishType Pre_Cfg_VoltageStats =
{
    V1,
    95,
};

void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned char data)
{
    if (state == FAULT)
    {
        Pre_CfgState.fault = data;
    }
    else if (state == CLOCK)
    {
        Pre_CfgState.clock = data;
    }
    else if (state == PRE_VOLTAGE)
    {
        Pre_CfgState.pre_voltage = data;
    }
    else
    {
    }
}

int Pre_Cfg_Fault(void)                           //配置错误函数:0无错,1有错
{
    return Pre_CfgState.fault;                                  //通过返回接收的CAN数字段0
}

int Pre_Cfg_Clock(void)                           //配置预充等待时间函数:单位秒，小于3秒
{
    return Pre_CfgState.clock;                 //通过返回接收的CAN数字段1
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)      //获取目标电压
{
    int rebuf = 0;
    if (object == BAT)
    {
        rebuf = Pre_CfgState.pre_voltage;
    }
    else if (object == V1)
    {
        rebuf = 100;
    }
    else if (object == V2)
    {
        rebuf = 120;
    }
    else if (object == V3)
    {
        rebuf = 140;
    }
    else
    {
    }
    return rebuf;
}