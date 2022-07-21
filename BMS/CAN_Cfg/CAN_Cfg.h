#ifndef __CAN_CFG_H
#define __CAN_CFG_H

#include "CAN.h"

extern CAN_MsgType CAN_CfgMsg1Type;
extern CAN_MsgType CAN_CfgMsg2Type;
extern CAN_MsgType CAN_CfgMsg3Type;
extern CAN_MsgType CAN_CfgPreStateOut_TestType;
extern CAN_ConfigType CAN_CfgHwType;
extern int begin;								//预充电开始信号

void CAN1_GetToSend(void);						//CAN1接受数据再发送
void CAN1_SendDemo(void);						//CAN1发送演示

#endif