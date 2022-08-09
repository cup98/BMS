#include "PrechargeM.h"
#include "Pre_LCfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)          //Ԥ���ʼ������
{
}

void PrechargeM_StartPre(void)      //�պ�Ԥ�俪��
{
    if (RelayM_Control(0 ,RELAYM_CTRL_STATUS ,1))
    {
    }
    //��¼ʱ��ռλ
}

void PrechargeM_StopPre(void)       //�Ͽ�Ԥ�俪��
{
    if (RelayM_Control(0 ,RELAYM_CTRL_STATUS ,0))
    {
    }
}

void PrechargeM_StartMaster(void)   //�պ���������
{
    if (RelayM_Control(1 ,RELAYM_CTRL_STATUS ,1))
    {
    }
}

void PrechargeM_StopMaster(void)    //�Ͽ���������
{
    if (RelayM_Control(1 ,RELAYM_CTRL_STATUS ,0))
    {
    }
}

void PrechargeM_Change(void)        //�̵����л�����
{
    PrechargeM_StartMaster();       //�պ�����
    PrechargeM_StopPre();           //�Ͽ�Ԥ��
}

int PrechargeM_IsFail()             //��ʱ�жϺ���
{                                   //�ж�������Ԥ�����˿̵�ʱ���Ƿ񳬹�3��
    int rebuf = 0;
    if (Pre_Cfg_Clock() <= Pre_Cfg_TimeOut.second)
    {
        rebuf = 0;
    }
    else
    {
        rebuf = 1;
    }
    return rebuf;
}

int PrechargeM_IsFinish()           //Ԥ������жϺ���
{
    int rebuf = 0;
    if (Hv_Get((uint8)Pre_CfgState.pre_voltage ,HV_VOLTAGE) * 100 >=
        Hv_Get(0 ,HV_VOLTAGE) * (Pre_CfgState.percent))   //�ж�V1��ѹ�Ƿ����BAT��ѹ��95%
    {
        rebuf = 1;
    }
    else
    {
        rebuf = 0;
    }
    return rebuf;
}



