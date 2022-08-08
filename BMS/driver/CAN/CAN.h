#ifndef __CAN_H
#define __CAN_H

#include "hidef.h"
#include "derivative.h"

#define CAN_MSG_MAXLEN 8                //设置数据最大长度8字节

typedef struct _CAN_MsgType             //构造CAN通信报文结构
{
    unsigned long ID;                   //仲裁帧id
    int IDE;                            //IDE:0标准帧,1扩展帧
    int RTR;                            //RTR:0数据帧,1远程帧
    unsigned int data[CAN_MSG_MAXLEN]; //数据位
    unsigned char len;                  //数据长度
    unsigned char prty;
} CAN_MsgType;

typedef enum _CAN_BpsCfgType            //CAN波特率选择
{
    CAN_BPS_20K,
    CAN_BPS_50K,
    CAN_BPS_100K,
    CAN_BPS_125K,
    CAN_BPS_250K,
    CAN_BPS_500K,
    CAN_BPS_800K,
    CAN_BPS_1000K
} CAN_BpsCfgType;

typedef struct _CAN_ConfigType          //CAN模式配置
{
    CAN_BpsCfgType bps;
    unsigned char sp;
} CAN_ConfigType;

extern void CAN_Init(void);                     //CAN初始化
extern void CAN1_Init(CAN_ConfigType *can_cfg); //CAN1初始化(CAN模式配置结构体)
extern int CAN1_SendMsg(CAN_MsgType *can_msg);  //CAN发送报文函数(CAN报文数据结构体)
extern int CAN1_GetMsg(CAN_MsgType *can_msg);   //CAN接受报文函数(CAN报文数据结构体)
extern void CAN_Delay10ms(unsigned int i);
//extern int CAN1_GetChoiceMsg(CAN_MsgType *can_msg ,unsigned long id ,int ide);//接收指定类型的报文


#endif

