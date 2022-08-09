#include "PrechargeM.h"
#include "Pre_LCfg.h"
#include "RelayM.h"
#include "Hv.h"

void PrechargeM_Init(void)          //预充初始化函数
{
}

void PrechargeM_StartPre(void)      //闭合预充开关
{
    if (RelayM_Control(0 ,RELAYM_CTRL_STATUS ,1))
    {
    }
    //记录时间占位
}

void PrechargeM_StopPre(void)       //断开预充开关
{
    if (RelayM_Control(0 ,RELAYM_CTRL_STATUS ,0))
    {
    }
}

void PrechargeM_StartMaster(void)   //闭合总正函数
{
    if (RelayM_Control(1 ,RELAYM_CTRL_STATUS ,1))
    {
    }
}

void PrechargeM_StopMaster(void)    //断开总正函数
{
    if (RelayM_Control(1 ,RELAYM_CTRL_STATUS ,0))
    {
    }
}

void PrechargeM_Change(void)        //继电器切换函数
{
    PrechargeM_StartMaster();       //闭合总正
    PrechargeM_StopPre();           //断开预充
}

int PrechargeM_IsFail()             //超时判断函数
{                                   //判断自启动预充至此刻的时间是否超过3秒
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

int PrechargeM_IsFinish()           //预充完成判断函数
{
    int rebuf = 0;
    if (Hv_Get((uint8)Pre_CfgState.pre_voltage ,HV_VOLTAGE) * 100 >=
        Hv_Get(0 ,HV_VOLTAGE) * (Pre_CfgState.percent))   //判断V1电压是否大于BAT电压的95%
    {
        rebuf = 1;
    }
    else
    {
        rebuf = 0;
    }
    return rebuf;
}



