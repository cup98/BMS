#include "CAN_App.h"
#include "Pre_Cfg.h"
#include "Node_cfg.h"
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


CAN_MsgType CAN_NodeState =
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

void CAN_Get_PreCfg(void)                                           //读取CAN报文内数据字段的数据给Pre配置
{
    if (CAN1_GetMsg(&CAN_PrechargeCfg) == 1)
    {
        Pre_Cfg_WriteCfg(PRE_CFG_FAULT ,CAN_PrechargeCfg.data[0]);  //data[0]字段赋值给Pre_Fault
        Pre_Cfg_WriteCfg(PRE_CFG_CLOCK ,CAN_PrechargeCfg.data[1]);  //data[1]字段赋值给Pre_Clock
        Pre_Cfg_WriteCfg(PRE_CFG_VOLTAGE ,CAN_PrechargeCfg.data[2]);//data[2]字段赋值给Pre_Voltage
        Pre_Cfg_WriteCfg(PRE_CFG_PERCENT ,CAN_PrechargeCfg.data[3]);//data[2]字段赋值给Pre_Voltage
        if (CAN1_SendMsg(&CAN_PrechargeCfg) == 1)                   //将接收的数据发送回去
        {
        }
    }
}

void CAN_Send_NodeState(void)                                       //将Node当前运行状态用CAN报文发送出来
{
    CAN_NodeState.data[0] = (unsigned char)Node_StateBack(NODE_CURRENT_STATE);//读取当前节点状态赋值到data[0]字段
    CAN_NodeState.data[1] = (unsigned char)Node_StateBack(NODE_NEXT_STATE);   //读取下一节点状态赋值到data[1]字段
    CAN_NodeState.data[7] = (unsigned char)Node_StateBack(NODE_BRANCH_NUM);   //读取当前节点分支数赋值到data[2]字段
    if (CAN1_SendMsg(&CAN_NodeState) == 1)                                    //将重构的报文通过CAN发出
    {
    }
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED

void interrupt VectorNumber_Vcan1rx CAN_receive(void)
{
    CAN_Get_PreCfg();                                               //在CAN接收中断来执行读取字段并赋值操作
}

void interrupt VectorNumber_Vpit0 PIT0(void)
{
    PITTF_PTF0 = 1;
    Node_Poll();                                                    //在PIT中断来执行节点程序和节点状态发送程序
    CAN_Send_NodeState();
}

#pragma CODE_SEG DEFAULT
