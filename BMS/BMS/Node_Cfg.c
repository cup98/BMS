#include "Node_Cfg.h"


//节点状态转换表
const Node_StateType Node_Pre_StateStart[] =
{
    {NODE0 ,Pre_Cfg_Fault ,1 ,Node_NoAct ,NODE0 },
    {NODE0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,NODE1 },
};

const Node_StateType Node_Pre_StateFinish[] =
{
    {NODE1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,NODE0 },
    {NODE1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,NODE0 },
    {NODE1 ,PrechargeM_IsFinish,0 ,Node_NoAct ,NODE1 },
    {NODE1 ,PrechargeM_IsFinish,1 ,PrechargeM_Change ,NODE2 },
};

const Node_StateType Node_Pre_StateFault[] =
{
    {NODE2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,NODE0 },
    {NODE2 ,Pre_Cfg_Fault ,0 ,Node_NoAct ,NODE2 },
};

const Node_StateCfgType Node_StateCfg[] =
{
    {2 ,Node_Pre_StateStart},
    {4 ,Node_Pre_StateFinish},
    {2 ,Node_Pre_StateFault},
};


