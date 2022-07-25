#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

typedef struct _Pre_Cfg_IsFailType  //构建节点状态机结构体
{
    int second;
} Pre_Cfg_IsFailType;

typedef struct _Pre_Cfg_IsFinishType  //构建节点状态机结构体
{
    Hv_Voltage_Type object; //当前节点
    int percent;
} Pre_Cfg_IsFinishType;

extern int Pre_Cfg_Fault(void);							//配置错误函数:0无错,1有错
extern int Pre_Cfg_Clock(void);							//配置预充等待时间函数:单位秒，小于3秒
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//获取目标电压(目标BAT/V1)
extern Pre_Cfg_IsFailType pre_cfg_max_time;
extern Pre_Cfg_IsFinishType pre_cfg_voltage_stats;


#endif