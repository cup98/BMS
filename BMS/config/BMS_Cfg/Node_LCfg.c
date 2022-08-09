#include "Node_LCfg.h"
#include "Pre_LCfg.h"
#include "PrechargeM.h"

const Node_StateInfoType Node_Fault_State[] =         //判断故障节点
{
    {NODE_0 ,Pre_Cfg_Fault ,1 ,Node_NoAct ,NODE_0 },
    {NODE_0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,NODE_1 },
};

const Node_StateInfoType Node_PreFinish_State[] =    //预充完成判断节点
{
    {NODE_1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,NODE_0 },
    {NODE_1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,NODE_0 },
    {NODE_1 ,PrechargeM_IsFinish ,0 ,Node_NoAct ,NODE_1 },
    {NODE_1 ,PrechargeM_IsFinish ,1 ,PrechargeM_Change ,NODE_2 },
};

const Node_StateInfoType Node_Charge_State[] =       //放电故障判断节点
{
    {NODE_2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,NODE_0 },
    {NODE_2 ,Pre_Cfg_Fault ,0 ,Node_NoAct ,NODE_2 },
};

const Node_StateCfgType Node_StateCfg[] =       //节点状态转换表
{
    {2 ,Node_Fault_State},
    {4 ,Node_PreFinish_State},
    {2 ,Node_Charge_State},
};

Node_ElementBackType Node_ElementBack;

