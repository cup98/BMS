#include "RelayM.h"

RelayM_CtrlType RelayM_Ctrl =                                   //��ʼ���̵���״̬
{
    0,
    0,
};

RelayM_SwitchType RelayM_Switch =                                   //��ʼ������״̬
{
    0,
    0,
};

void RelayM_Init(void)                                      //�̵���ģ���ɳ�ʼ������
{
}

void RelayM_Control(RelayM_Object_Type object ,int state)   //���Ƽ̵������غ���(����Ŀ��,״̬)
{
    if (object == RELAYM_MASTER)
    {
        RelayM_Ctrl.Master = state;
    }
    else if (object == RELAYM_PRECHANG)
    {
        RelayM_Switch.Precharge = state;
    }
}

void RelayM_Change(RelayM_Object_Type object ,int state)    //�л����غ���(����Ŀ��,״̬)
{
    if (object == RELAYM_MASTER)
    {
        RelayM_Ctrl.Master  = state;
    }
    else if (object == RELAYM_PRECHANG)
    {
        RelayM_Switch.Precharge = state;
    }
}
