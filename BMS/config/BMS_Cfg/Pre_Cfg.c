#include "Pre_Cfg.h"

Pre_CfgStateType Pre_CfgState;

Pre_Cfg_TimeOutType Pre_Cfg_TimeOut =
{
    3,
};

Pre_Cfg_VoltageStdType Pre_Cfg_VoltageStd =
{
    HV_V1,
    95,
};

void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned char data) //将数据存入相应的配置结构体内
{
    if (state == PRE_CFG_FAULT)
    {
        Pre_CfgState.fault = data;
    }
    else if (state == PRE_CFG_CLOCK)
    {
        Pre_CfgState.clock = data;
    }
    else if (state == PRE_CFG_VOLTAGE)
    {
        Pre_CfgState.pre_voltage = data;
    }
    else
    {
    }
}

int Pre_Cfg_Fault(void)                                         //配置错误函数:0无错,1有错
{
    return Pre_CfgState.fault;
}

int Pre_Cfg_Clock(void)                                         //配置预充等待时间函数:单位秒，小于3秒
{
    return Pre_CfgState.clock;
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)                  //获取目标电压
{
    int rebuf = 0;
    if (object == HV_BAT)
    {
        rebuf = Pre_CfgState.pre_voltage;
    }
    else if (object == HV_V1)
    {
        rebuf = 100;
    }
    else if (object == HV_V2)
    {
        rebuf = 120;
    }
    else if (object == HV_V3)
    {
        rebuf = 140;
    }
    else
    {
    }
    return rebuf;
}