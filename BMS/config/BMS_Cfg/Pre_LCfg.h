#ifndef __PRE_LCFG_H
#define __PRE_LCFG_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

typedef enum _Pre_State_Type        //构建预充配置名称
{
    PRE_CFG_FAULT,                  //故障判断
    PRE_CFG_CLOCK,                  //预充超时判断
    PRE_CFG_VOLTAGE,                //预充电压配置
    PRE_CFG_PERCENT,
} Pre_State_Type;

typedef struct _Pre_CfgStateType    //构建预充配置存储结构体
{
    unsigned char fault;            //储存故障
    unsigned char clock;            //储存时间
    unsigned char pre_voltage;      //储存电压
    unsigned char percent;
} Pre_CfgStateType;

typedef struct _Pre_Cfg_TimeOutType  //构建预充超时截止时间结构体
{
    int second;
} Pre_Cfg_TimeOutType;

typedef struct _Pre_Cfg_VoltageStdType  //构建节点状态机结构体
{
    uint8 channel;
    int percent;
} Pre_Cfg_VoltageStdType;

extern Pre_CfgStateType Pre_CfgState;
extern Pre_Cfg_TimeOutType Pre_Cfg_TimeOut;
extern Pre_Cfg_VoltageStdType Pre_Cfg_VoltageStd;
extern void Pre_Cfg_WriteCfg(Pre_State_Type state ,unsigned char data); //将数据存入相应的配置结构体内（目标，数据）
extern int Pre_Cfg_Fault(void);                                         //读取错误函数，返回：0无错，1有错
extern int Pre_Cfg_Clock(void);                                         //读取预充等待时间函数，返回：单位秒，小于3秒
extern int Per_Cfg_GetVoltage(uint8 channel);                  //获取目标电压(目标)，返回：电压值

#endif