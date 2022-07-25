#include "Node_Cfg.h"
#include "Node.h"
#include "Pre_Cfg.h"

/*Node_StateType Pre_Cfg_NodeStateType[] =         //节点状态转换表
{
 	{Node0 ,Pre_Cfg_Fault ,1 ,Node_No_Act ,Node0 },
 	{Node0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,Node1 },
 	{Node1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,Node0 },
 	{Node1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,Node0 },
 	{Node1 ,PrechargeM_IsFinish ,1 ,PrechargeM_Change ,Node2 },
 	{Node1 ,PrechargeM_IsFinish ,0 ,Node_No_Act ,Node1 },
 	{Node2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,Node0 },
 	{Node2 ,Pre_Cfg_Fault ,0 ,Node_No_Act ,Node2 },
};*/


const Node_StateType node_pre_state_start[] =
{
    {NODE0 ,Pre_Cfg_Fault ,1 ,Node_NoAct ,NODE0 },
    {NODE0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,NODE1 },
};

const Node_StateType node_pre_state_finish[] =
{
    {NODE1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,NODE0 },
    {NODE1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,NODE0 },
    {NODE1 ,PrechargeM_IsFinish,0 ,Node_NoAct ,NODE1 },
    {NODE1 ,PrechargeM_IsFinish,1 ,PrechargeM_Change ,NODE2 },
};

const Node_StateType node_pre_state_fault[] =
{
    {NODE2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,NODE0 },
    {NODE2 ,Pre_Cfg_Fault ,0 ,Node_NoAct ,NODE2 },
};

const Node_StateCfgType node_state_cfg[] =
{
    {2, node_pre_state_start},
    {4, node_pre_state_finish},
    {2, node_pre_state_fault},
};

Node_StateInfoType node_state_info;
