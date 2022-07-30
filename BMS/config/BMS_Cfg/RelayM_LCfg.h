#ifndef __RELAYM_LCFG_H
#define __RELAYM_LCFG_H

#include "RelayM.h"

#define RELAYM_MAX_NUM  8 					//继电器控制最大数量

#define RELAYM_CONTROL_SUPPORT	 TRUE		//继电器支持控制状态功能
#define RELAYM_ON_TIME_SUPPORT   TRUE		//继电器支持设置闭合时间功能
#define RELAYM_OFF_TIME_SUPPORT  TRUE		//继电器支持设置断开时间功能
#define RELAYM_RES_VALUE_SUPPORT TRUE		//继电器支持设置内阻功能

#define GPIO_0	((uint16)0x0001)
#define GPIO_1	((uint16)0x0002)
#define GPIO_2	((uint16)0x0004)
#define GPIO_3	((uint16)0x0008)
#define GPIO_4	((uint16)0x0010)
#define GPIO_5	((uint16)0x0020)
#define GPIO_6	((uint16)0x0040)
#define GPIO_7	((uint16)0x0080)

extern RelayM_ControlType RelayM_CtrlData[RELAYM_MAX_NUM];      //继电器控制数据
extern RelayM_ActureType RelayM_ActureData[RELAYM_MAX_NUM];     //继电器当前数据

#endif