#include "RelayM.h"
#include "RelayM_Cfg.h"

void RelayM_Init(void)                                      //继电器模块由初始化函数
{
}

void RelayM_Control(RelayM_Object_Type object ,int state)   //控制继电器开关函数(控制目标,状态)
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

void RelayM_Change(RelayM_Object_Type object ,int state)    //切换开关函数(控制目标,状态)
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
