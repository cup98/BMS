#ifndef __CAN_CFG_H
#define __CAN_CFG_H

#include "CAN.h"

extern CAN_ConfigType can_hwcfg;
extern CAN_MsgType msg1;
extern CAN_MsgType msg2;
extern CAN_MsgType msg3;
extern CAN_MsgType back_data_buf;
extern CAN_MsgType receive_buf;
//extern CAN_MsgType CAN_CfgPreStateOut_TestType;

extern int begin;								//预充电开始信号

extern void CAN1_GetToSend(void);						//CAN1接受数据再发送
extern void CAN1_SendDemo(void);						//CAN1发送演示
extern void CAN_GetToMsg_data(int byte_num ,unsigned char data);

#endif