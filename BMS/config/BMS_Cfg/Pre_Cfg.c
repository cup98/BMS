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

int Pre_Cfg_Fault(void)                           //���ô�����:0�޴�,1�д�
{
    return Pre_CfgState.fault;                                  //ͨ�����ؽ��յ�CAN���ֶ�0
}

int Pre_Cfg_Clock(void)                           //����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
{
    return Pre_CfgState.clock;                 //ͨ�����ؽ��յ�CAN���ֶ�1
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)      //��ȡĿ���ѹ
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