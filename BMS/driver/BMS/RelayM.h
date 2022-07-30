#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"

#define RELAYM_MAX_NUM     8
#define RELAYM_RES_SUPPORT TRUE

typedef unsigned char      uint8;
typedef unsigned short int uint16;
typedef unsigned int       uint32;

typedef enum _RelayM_FaultStatusType
{
    RELAYM_NORMAL,
    RELAYM_ADHESION,
    RELAYM_OPEN_LOOP,
} RelayM_FaultStatusType;

typedef enum _RelayM_AttributeType
{
    RELAYM_ACTURE_CONTROL,
    RELAYM_ACTURE_STATUS,
    RELAYM_ACTURE_ON_TIME,
    RELAYM_ACTURE_OFF_TIME,
    RELAYM_ACTURE_RES_VALUE,
    RELAYM_CTRL_STATUS,
    RELAYM_CTRL_ON_TIME,
    RELAYM_CTRL_OFF_TIME,
    RELAYM_CTRL_RES_VALUE,
} RelayM_AttributeType;

typedef enum _RelayM_ChannelType
{
    RelayM_Channel_0,
    RelayM_Channel_1,
    RelayM_Channel_2,
    RelayM_Channel_3,
    RelayM_Channel_4,
    RelayM_Channel_5,
    RelayM_Channel_6,
    RelayM_Channel_7,
} RelayM_ChannelType;

typedef struct _RelayM_ControlType/*控制状态，需要设置的状态*/
{
    uint32 ctrl_status;/*继电器控制状态*/
    uint32 on_time;/*继电器控制闭合时间*/
    uint32 off_time;/*继电器控制断开时间*/
    uint32 res_value;/*继电器内阻设置*/
} RelayM_ControlType;

typedef struct _RelayM_ActureType
{
    uint32 *acture_status;
    uint32 *on_time;
    uint32 *off_time;
    uint32 *res_value;
} RelayM_ActureType;

/*typedef struct _RelayM_InfoType
{
    uint8 channel;
    RelayM_ActureType *acture_data;
    RelayM_CtrlDataType *Control_data;
    RelayM_FaultStatusType fault;
} RelayM_InfoType;

RelayM_InfoType RelayM_Info[RELAYM_MAX_NUM] =
{
    {0 ,&RelayM_Acture[0] ,&RelayM_CtrlData[0] ,RELAYM_NORMAL};
    {1 ,&RelayM_Acture[1] ,&RelayM_CtrlData[1] ,RELAYM_NORMAL};
    {2 ,&RelayM_Acture[2] ,&RelayM_CtrlData[2] ,RELAYM_NORMAL};
    {3 ,&RelayM_Acture[3] ,&RelayM_CtrlData[3] ,RELAYM_NORMAL};
    {4 ,&RelayM_Acture[4] ,&RelayM_CtrlData[4] ,RELAYM_NORMAL};
    {5 ,&RelayM_Acture[5] ,&RelayM_CtrlData[5] ,RELAYM_NORMAL};
    {6 ,&RelayM_Acture[6] ,&RelayM_CtrlData[6] ,RELAYM_NORMAL};
    {7 ,&RelayM_Acture[7] ,&RelayM_CtrlData[7] ,RELAYM_NORMAL};
}; */

extern void RelayM_Init(void);                                      //继电器模块由初始化函数
extern void RelayM_InterruptON(void);
extern void RelayM_InterruptOFF(void);
extern void RelayM_SetContorl(uint8 channel ,uint32 value);
extern uint32 RelayM_GetControl(uint8 channel);
extern uint32 RelayM_GetActure(uint8 channel);
extern uint32 RelayM_GetOnTime(uint8 channel);
extern void RelayM_SetOnTime(uint8 channel ,uint32 value);
extern uint32 RelayM_GetOffTime(uint8 channel);
extern void RelayM_SetOffTime(uint8 channel ,uint32 value);
extern uint32 RelayM_GetRes(uint8 channel);
extern void RelayM_SetRes(uint8 channel ,uint32 value);
extern RelayM_FaultStatusType RelayM_GetFault(uint8 channel);
extern void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value);   //控制继电器开关函数,控制继电器开关函数(控制目标,状态)
extern uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute);

#endif