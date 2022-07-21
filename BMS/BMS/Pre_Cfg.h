#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

extern const unsigned char Node_Num;

extern int Pre_Cfg_Fault(void);							//配置错误函数:0无错,1有错
extern int Pre_Cfg_Clock(void);							//配置预充等待时间函数:单位秒，小于3秒
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//获取目标电压(目标BAT/V1)
extern Node_StateType Pre_Cfg_NodeStateType[];

#endif