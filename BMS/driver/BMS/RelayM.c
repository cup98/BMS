#include "RelayM.h"
#include "RelayM_Cfg.h"

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
