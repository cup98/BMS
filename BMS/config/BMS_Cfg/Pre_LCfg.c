#include "Pre_LCfg.h"
#include "HV.h"

Pre_CfgStateType Pre_CfgState;

Pre_Cfg_TimeOutType Pre_Cfg_TimeOut =
{
    3,
};

Pre_Cfg_VoltageStdType Pre_Cfg_VoltageStd =
{
    1,
    95,
};

void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned int data) //�����ݴ�����Ӧ�����ýṹ����
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
    else if (state == PRE_CFG_PERCENT)
    {
        Pre_CfgState.percent = data;
    }
    else
    {
    }
}

int Pre_Cfg_Fault(void)                                         //���ô�����:0�޴�,1�д�
{
    return Pre_CfgState.fault;
}

int Pre_Cfg_Clock(void)                                         //����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
{
    return Pre_CfgState.clock;
}

int Per_Cfg_GetVoltage(uint8 channel)                  //��ȡĿ���ѹ
{
    int rebuf = 0;
    if (channel == 0)
    {
        rebuf = Pre_CfgState.pre_voltage;
    }
    else
    {
        rebuf = Hv_Get(channel ,HV_VOLTAGE);
    }
    return rebuf;
}