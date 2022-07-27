#include "CAN_App.h"
#include "Pre_Cfg.h"
#include "Node.h"

CAN_MsgType CAN_DemoMsg1 =
{
    0x01F,
    0,
    0,
    {1,1,1,1,1,1,1,1},
    8,
    0,
};

CAN_MsgType CAN_DemoMsg2 =
{
    0x1FFFFFFF,
    1,
    0,
    {2,2,2,2,2,2,2,2},
    8,
    0,
};

CAN_MsgType CAN_DemoMsg3 =
{
    0x03,
    0,
    1,
    {3,3,3,3,3,3,3,3},
    8,
    0,
};

CAN_MsgType CAN_PrechargeCfg =
{
    0x5FF,
    0,
    0,
    {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    8,
    0,
};


CAN_MsgType CAN_NodeData =
{
    0x111,
    0,
    0,
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    8,
    0,
};

void CAN_SendDemo(void)
{
    static int CAN_Time = 0;
    CAN_Time++;
    if (CAN_Time == 1)
    {
        if (CAN1_SendMsg(&CAN_DemoMsg1) == 1)
        {
        }
    }
    else if (CAN_Time == 2)
    {
        if (CAN1_SendMsg(&CAN_DemoMsg2) == 1)
        {
        }
    }
    else if (CAN_Time == 3)
    {
        if (CAN1_SendMsg(&CAN_DemoMsg3) == 1)
        {
        }
        CAN_Time = 0;
    }
    else
    {
    }
}

void CAN_Get_PreCfg(void)                                   //璇诲嚭鎺ュ彈鍒扮殑鏁版嵁鍐嶅彂閫佸嚭鏉
{
    if (CAN1_GetMsg(&CAN_PrechargeCfg) == 1)
    {
        Pre_Cfg_WriteCfg(PRE_CFG_FAULT ,CAN_PrechargeCfg.data[0]);
        Pre_Cfg_WriteCfg(PRE_CFG_CLOCK ,CAN_PrechargeCfg.data[1]);
        Pre_Cfg_WriteCfg(PRE_CFG_VOLTAGE ,CAN_PrechargeCfg.data[2]);
        if (CAN1_SendMsg(&CAN_PrechargeCfg) == 1)
        {
        }
    }
}

void CAN_Send_NodeState(void)
{
    CAN_NodeData.data[0] = (unsigned char)Node_StateBack(NODE_CURRENT_STATE);
    CAN_NodeData.data[1] = (unsigned char)Node_StateBack(NODE_NEXT_STATE);
    CAN_NodeData.data[7] = (unsigned char)Node_StateBack(NODE_BRANCH_NUM);
    if (CAN1_SendMsg(&CAN_NodeData) == 1)
    {
    }
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED

void interrupt VectorNumber_Vcan1rx CAN_receive(void)
{
    CAN_Get_PreCfg();
}

void interrupt VectorNumber_Vpit0 PIT0(void)                //涓柇鏈嶅姟鍑芥暟
{
    PITTF_PTF0 = 1;
    CAN_Send_NodeState();
    Node_Poll();
}

#pragma CODE_SEG DEFAULT
