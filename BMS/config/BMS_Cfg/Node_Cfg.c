#include "Node_Cfg.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"

//节点状态转换表
const Node_StateType Node_Pre_StateStart[] =
{
    {NODE_0 ,Pre_Cfg_Fault ,1 ,Node_NoAct ,NODE_0 },
    {NODE_0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,NODE_1 },
};

const Node_StateType Node_Pre_StateFinish[] =
{
    {NODE_1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,NODE_0 },
    {NODE_1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,NODE_0 },
    {NODE_1 ,PrechargeM_IsFinish ,0 ,Node_NoAct ,NODE_1 },
    {NODE_1 ,PrechargeM_IsFinish ,1 ,PrechargeM_Change ,NODE_2 },
};

const Node_StateType Node_Pre_StateFault[] =
{
    {NODE_2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,NODE_0 },
    {NODE_2 ,Pre_Cfg_Fault ,0 ,Node_NoAct ,NODE_2 },
};

const Node_StateCfgType Node_StateCfg[] =
{
    {2 ,Node_Pre_StateStart},
    {4 ,Node_Pre_StateFinish},
    {2 ,Node_Pre_StateFault},
};


