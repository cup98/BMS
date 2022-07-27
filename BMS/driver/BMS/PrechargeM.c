#include "PrechargeM.h"
#include "Pre_Cfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)          //Ԥ���ʼ������
{
}

void PrechargeM_StartPre(void)      //�պ�Ԥ�俪��
{
    RelayM_Control(RELAYM_PRECHANG ,1);
    //��¼ʱ��ռλ
}

void PrechargeM_StopPre(void)       //�Ͽ�Ԥ�俪��
{
    RelayM_Control(RELAYM_PRECHANG ,0);
}

void PrechargeM_StartMaster(void)   //�պ���������
{
    RelayM_Control(RELAYM_MASTER ,1);
}

void PrechargeM_StopMaster(void)    //�Ͽ���������
{
    RelayM_Control(RELAYM_MASTER ,0);
}

void PrechargeM_Change(void)        //�̵����л�����
{
    PrechargeM_StartMaster();       //�պ�����
    PrechargeM_StopPre();           //�Ͽ�Ԥ��
}

int PrechargeM_IsFail()             //��ʱ�жϺ���
{                                   //�ж�������Ԥ�����˿̵�ʱ���Ƿ񳬹�3��
    int rebuf;
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
    int rebuf;
    if (Hv_Get(Pre_Cfg_VoltageStd.object) * 100 >=
        Hv_Get(HV_BAT) * (Pre_Cfg_VoltageStd.percent))   //�ж�V1��ѹ�Ƿ����BAT��ѹ��95%
    {
        rebuf = 1;
    }
    else
    {
        rebuf = 0;
    }
    return rebuf;
}



