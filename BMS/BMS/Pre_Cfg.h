#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"

extern int Pre_Cfg_Fault(void);

extern int Pre_Cfg_Clock(void);

typedef struct _Pre_Cfg_GetHvVoltageType         //构建电压值结构体
{
    int BAT;                //BAT电压
    int V1;                 //V1电压
} Pre_Cfg_GetHvVoltageType;

extern Pre_Cfg_GetHvVoltageType Per_Cfg_GetVoltageType;
                                 
#endif