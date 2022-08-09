#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"
#include "STD.h"

typedef enum _RelayM_FaultStatusType//继电器故障类型
{
    RELAYM_NORMAL,
    RELAYM_ADHESION,
    RELAYM_OPEN_LOOP,
} RelayM_FaultStatusType;

typedef enum _RelayM_ActureAttributeType //继电器属性
{
    RELAYM_ACTURE_CONTROL,
    RELAYM_ACTURE_STATUS,
    RELAYM_ACTURE_ON_TIME,
    RELAYM_ACTURE_OFF_TIME,
    RELAYM_ACTURE_RES_VALUE
} RelayM_ActureAttributeType;

typedef enum _RelayM_CtrlAttributeType //继电器属性
{
    RELAYM_CTRL_STATUS,
    RELAYM_CTRL_ON_TIME,
    RELAYM_CTRL_OFF_TIME,
    RELAYM_CTRL_RES_VALUE
} RelayM_CtrlAttributeType;

typedef struct _RelayM_ControlType //控制状态
{
    uint32 ctrl_status;            //继电器控制状态
    uint32 on_time;                //继电器控制闭合时间
    uint32 off_time;               //继电器控制断开时间
    uint32 res_value;              //继电器内阻设置
} RelayM_ControlType;

typedef struct _RelayM_ActureType  //继电器当前状态数据
{
    uint32 *acture_status;
    uint32 *on_time;
    uint32 *off_time;
    uint32 *res_value;
} RelayM_ActureType;

typedef struct _RelayM_InfoType
{
    uint8 channel;
    RelayM_ActureType *acture_data;
    RelayM_ControlType *Control_data;
    RelayM_FaultStatusType fault;
} RelayM_InfoType;

/*RelayM_InfoType RelayM_Info[RELAYM_MAX_NUM] =
{
    {0 ,&RelayM_Acture[0] ,&RelayM_CtrlData[0] ,RELAYM_NORMAL};
    {1 ,&RelayM_Acture[1] ,&RelayM_CtrlData[1] ,RELAYM_NORMAL};
    {2 ,&RelayM_Acture[2] ,&RelayM_CtrlData[2] ,RELAYM_NORMAL};
    {3 ,&RelayM_Acture[3] ,&RelayM_CtrlData[3] ,RELAYM_NORMAL};
    {4 ,&RelayM_Acture[4] ,&RelayM_CtrlData[4] ,RELAYM_NORMAL};
    {5 ,&RelayM_Acture[5] ,&RelayM_CtrlData[5] ,RELAYM_NORMAL};
    {6 ,&RelayM_Acture[6] ,&RelayM_CtrlData[6] ,RELAYM_NORMAL};
    {7 ,&RelayM_Acture[7] ,&RelayM_CtrlData[7] ,RELAYM_NORMAL};
};*/

extern void RelayM_Init(void);                                      //继电器驱动由初始化函数
extern void RelayM_InterruptON(void);                               //继电器驱动开中断
extern void RelayM_InterruptOFF(void);                              //继电器驱动关中断
extern uint8 RelayM_SetContorl(uint8 channel ,uint32 value);         //设置继电器状态
extern uint32 RelayM_GetControl(uint8 channel);                     //获取继电器状态
extern uint32 RelayM_GetActure(uint8 channel);                      //获取继电器当前状态
extern uint32 RelayM_GetOnTime(uint8 channel);                      //获取继电器闭合时间
extern uint8 RelayM_SetOnTime(uint8 channel ,uint32 value);          //设置继电器闭合时间
extern uint32 RelayM_GetOffTime(uint8 channel);                     //获取继电器断开时间
extern uint8 RelayM_SetOffTime(uint8 channel ,uint32 value);         //设置继电器断开时间
extern uint32 RelayM_GetRes(uint8 channel);                         //获取继电器内阻值
extern uint8 RelayM_SetRes(uint8 channel ,uint32 value);             //设置继电器内阻值
extern RelayM_FaultStatusType RelayM_GetFault(uint8 channel);       //继电器故障检测
extern uint8 RelayM_Control(uint8 channel ,RelayM_CtrlAttributeType attribute ,uint32 value);   //控制继电器开关函数,控制继电器开关函数(控制目标,状态)
extern uint32 RelayM_Acture(uint8 channel ,RelayM_ActureAttributeType attribute);                //继电器当前状态获取(通道，属性)
uint8 (*RelayM_Set[])(uint8 ,uint32);
uint32 (*RelayM_Get[])(uint8);

#endif