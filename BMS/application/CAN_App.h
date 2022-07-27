#ifndef __CAN_APP_H
#define __CAN_APP_H

#include "hidef.h"
#include "derivative.h"
#include "CAN.h"

extern CAN_MsgType CAN_DemoMsg1;
extern CAN_MsgType CAN_DemoMsg2;
extern CAN_MsgType CAN_DemoMsg3;
extern CAN_MsgType CAN_PrechargeCfg;					//预充配置报文
extern CAN_MsgType CAN_NodeState;						//节点数据报文

extern void CAN_SendDemo(void);							//CAN发送演示
extern void CAN_Get_PreCfg(void);                       //CAN接受到预充配置
extern void CAN_Send_NodeState(void);					//CAN发送节点状态

#endif