#ifndef __RELAYM_LCFG_H
#define __RELAYM_LCFG_H

#include "RelayM.h"

#define RELAYM_MAX_NUM     8
#define RELAYM_RES_SUPPORT TRUE

extern RelayM_ControlType RelayM_CtrlData[RELAYM_MAX_NUM];      //继电器控制数据
extern RelayM_ActureType RelayM_ActureData[RELAYM_MAX_NUM];     //继电器当前数据

#endif