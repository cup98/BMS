#ifndef __PRECFG_H
#define __PRECFG_H

#include "hidef.h"
#include "derivative.h"

extern int PreCfg_Fault(void);

extern int PreCfg_Clock(void);

typedef struct _PreCfg_Get_HvVoltageType         //构建电压值结构体
{
    int BAT;                //BAT电压
    int V1;                 //V1电压
} PreCfg_Get_HvVoltageType;

extern PreCfg_Get_HvVoltageType PerCfg_GetVoltageType;

#endif