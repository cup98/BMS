#ifndef __CAN_CFG_H
#define __CAN_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "CAN.h"

extern CAN_ConfigType CAN_HwCfg;
extern CAN_MsgType Msg1;
extern CAN_MsgType Msg2;
extern CAN_MsgType Msg3;
extern CAN_MsgType CAN_Cfg_ReceiveBuf;
extern CAN_MsgType CAN_Cfg_BackDataBuf;
//extern CAN_MsgType CAN_CfgPreStateOut_TestType;

//extern int begin;								//预充电开始信号
extern void CAN1_SendDemo(void);//CAN1发送演示
extern void CAN_Get_PreCfg(void);						//CAN1接受数据再发送
extern void CAN_Send_PreNodeState(void);

#endif