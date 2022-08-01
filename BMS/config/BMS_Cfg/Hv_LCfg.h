#ifndef __HV_LCFG_H
#define __HV_LCFG_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

#define HV_MAX_NUM 8				//高压最大通道数

#define HV_VOLTAGE_MIN  (10U)		//高压模块测量范围
#define HV_CURRENT_MIN  (10U)
#define HV_TEMP_MIN     (10U)
#define HV_VOLTAGE_MAX  (100U)
#define HV_CURRENT_MAX  (100U)
#define HV_TEMP_MAX     (100U)

#define HV_VOLTAGE_(X)  (*(uint32 *)(&(Hv_DemoData[X].voltage)))
#define HV_CURRENT_(X)  (*(uint32 *)(&(Hv_DemoData[X].current)))
#define HV_TEMP_(X)     (*(uint32 *)(&(Hv_DemoData[X].temp)))

/*
#if (HV_MAX_NUM == 16)
    #define HV_IO_0   ((uint32)*(&(Hv_DemoData[0].voltage)))
    #define HV_IO_1   ((uint32)*(&(Hv_DemoData[1].voltage)))
    #define HV_IO_2   ((uint32)*(&(Hv_DemoData[2].voltage)))
    #define HV_IO_3   ((uint32)*(&(Hv_DemoData[3].voltage)))
    #define HV_IO_4   ((uint32)*(&(Hv_DemoData[4].voltage)))
    #define HV_IO_5   ((uint32)*(&(Hv_DemoData[5].voltage)))
    #define HV_IO_6   ((uint32)*(&(Hv_DemoData[6].voltage)))
    #define HV_IO_7   ((uint32)*(&(Hv_DemoData[7].voltage)))
    #define HV_IO_8   ((uint32)*(&(Hv_DemoData[8].voltage)))
    #define HV_IO_9   ((uint32)*(&(Hv_DemoData[9].voltage)))
    #define HV_IO_10  ((uint32)*(&(Hv_DemoData[10].voltage)))
    #define HV_IO_11  ((uint32)*(&(Hv_DemoData[11].voltage)))
    #define HV_IO_12  ((uint32)*(&(Hv_DemoData[12].voltage)))
    #define HV_IO_13  ((uint32)*(&(Hv_DemoData[13].voltage)))
    #define HV_IO_14  ((uint32)*(&(Hv_DemoData[14].voltage)))
    #define HV_IO_15  ((uint32)*(&(Hv_DemoData[15].voltage)))
#elif (HV_MAX_NUM == 8)
    #define HV_IO_0   ((uint32)*(&(Hv_DemoData[0].voltage)))
    #define HV_IO_1   ((uint32)*(&(Hv_DemoData[1].voltage)))
    #define HV_IO_2   ((uint32)*(&(Hv_DemoData[2].voltage)))
    #define HV_IO_3   ((uint32)*(&(Hv_DemoData[3].voltage)))
    #define HV_IO_4   ((uint32)*(&(Hv_DemoData[4].voltage)))
    #define HV_IO_5   ((uint32)*(&(Hv_DemoData[5].voltage)))
    #define HV_IO_6   ((uint32)*(&(Hv_DemoData[6].voltage)))
    #define HV_IO_7   ((uint32)*(&(Hv_DemoData[7].voltage)))
#endif
*/

extern Hv_DataType Hv_DemoData[HV_MAX_NUM];

#endif