#ifndef __CAN_APP_H
#define __CAN_APP_H

#include "hidef.h"
#include "derivative.h"
#include "CAN.h"

extern CAN_MsgType CAN_DemoMsg1;
extern CAN_MsgType CAN_DemoMsg2;
extern CAN_MsgType CAN_DemoMsg3;
extern CAN_MsgType CAN_PrechargeCfg;
extern CAN_MsgType CAN_NodeData;

extern void CAN_SendDemo(void);//CAN发送演示
extern void CAN_Get_PreCfg(void);                       //CAN接受数据再发送
extern void CAN_Send_NodeState(void);

#endif