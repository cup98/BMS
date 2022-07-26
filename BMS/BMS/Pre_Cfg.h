#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

typedef enum _Pre_State_Type     //列举节点数量名称
{
    FAULT,                      //判断故障节点
    CLOCK,                      //预充完成判断节点
    PRE_VOLTAGE,                      //放电故障判断节点
} Pre_State_Type;

typedef struct _Pre_CfgStateType  //构建节点状态机结构体
{
    unsigned char fault; //当前节点
    unsigned char clock;
    unsigned char pre_voltage;
} Pre_CfgStateType;

typedef struct _Pre_Cfg_IsFailType  //构建节点状态机结构体
{
    int second;
} Pre_Cfg_IsFailType;

typedef struct _Pre_Cfg_IsFinishType  //构建节点状态机结构体
{
    Hv_Voltage_Type object; //当前节点
    int percent;
} Pre_Cfg_IsFinishType;

extern void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned char data);
extern int Pre_Cfg_Fault(void);							//配置错误函数:0无错,1有错
extern int Pre_Cfg_Clock(void);							//配置预充等待时间函数:单位秒，小于3秒
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//获取目标电压(目标BAT/V1)
extern Pre_Cfg_IsFailType Pre_Cfg_MaxTime;
extern Pre_Cfg_IsFinishType Pre_Cfg_VoltageStats;
extern Pre_CfgStateType Pre_CfgState;

#endif