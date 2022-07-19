#ifndef __CAN_CFG_H
#define __CAN_CFG_H

#include "CAN.h"

extern CAN_MsgType CAN_CfgMsg1Type;
extern CAN_MsgType CAN_CfgMsg2Type;
extern CAN_MsgType CAN_CfgMsg3Type;
extern CAN_MsgType CAN_CfgPreStateOut_TestType;
extern CAN_ConfigType CAN_CfgHwType;

void CAN1_GetToSend(void);
void CAN1_SendDemo(void);

#endif