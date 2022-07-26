#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

extern void PrechargeM_Init(void);			//初始化函数
extern void PrechargeM_StartPre(void);		//启动预充函数,闭合预充开关
extern void PrechargeM_StopPre(void);		//停止预充函数,段开预充开关
extern void PrechargeM_StartMaster(void);	//闭合总正函数
extern void PrechargeM_StopMaster(void);	//断开总正函数
extern void PrechargeM_Change(void);		//继电器切换函数,闭合总正，断开预充
extern int PrechargeM_IsFinish(void);		//预充完成判断函数,判断V1电压是否大于BAT电压的95%
extern int PrechargeM_IsFail(void);			//超时判断函数,判断自启动预充至此刻的时间是否超过3秒

#endif