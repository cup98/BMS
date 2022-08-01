#ifndef __RELAYM_LCFG_H
#define __RELAYM_LCFG_H

#include "RelayM.h"

#define RELAYM_MAX_NUM  8                   //继电器控制最大数量

#define RELAYM_ON_TIME_SET_SUPPORT   TRUE       //继电器支持设置闭合时间功能
#define RELAYM_OFF_TIME_SET_SUPPORT  TRUE       //继电器支持设置断开时间功能
#define RELAYM_RES_VALUE_SET_SUPPORT TRUE       //继电器支持设置内阻功能


#define RELAYM_IO_(X)           (*(uint32 *)(&(RelayM_OriginDataDemo[X].ctrl_status)))
#define RELAYM_ON_TIME_(X)      (*(uint32 *)(&(RelayM_OriginDataDemo[X].on_time)))
#define RELAYM_OFF_TIME_(X)     (*(uint32 *)(&(RelayM_OriginDataDemo[X].off_time)))
#define RELAYM_RES_VALUE_(X)    (*(uint32 *)(&(RelayM_OriginDataDemo[X].res_value)))
/*
#if (RELAYM_MAX_NUM == 16)
    #define RELAYM_IO_0   ((uint32)*(&(RelayM_OriginDataDemo[0].ctrl_status)))
    #define RELAYM_IO_1   ((uint32)*(&(RelayM_OriginDataDemo[1].ctrl_status)))
    #define RELAYM_IO_2   ((uint32)*(&(RelayM_OriginDataDemo[2].ctrl_status)))
    #define RELAYM_IO_3   ((uint32)*(&(RelayM_OriginDataDemo[3].ctrl_status)))
    #define RELAYM_IO_4   ((uint32)*(&(RelayM_OriginDataDemo[4].ctrl_status)))
    #define RELAYM_IO_5   ((uint32)*(&(RelayM_OriginDataDemo[5].ctrl_status)))
    #define RELAYM_IO_6   ((uint32)*(&(RelayM_OriginDataDemo[6].ctrl_status)))
    #define RELAYM_IO_7   ((uint32)*(&(RelayM_OriginDataDemo[7].ctrl_status)))
    #define RELAYM_IO_8   ((uint32)*(&(RelayM_OriginDataDemo[8].ctrl_status)))
    #define RELAYM_IO_9   ((uint32)*(&(RelayM_OriginDataDemo[9].ctrl_status)))
    #define RELAYM_IO_10  ((uint32)*(&(RelayM_OriginDataDemo[10].ctrl_status)))
    #define RELAYM_IO_11  ((uint32)*(&(RelayM_OriginDataDemo[11].ctrl_status)))
    #define RELAYM_IO_12  ((uint32)*(&(RelayM_OriginDataDemo[12].ctrl_status)))
    #define RELAYM_IO_13  ((uint32)*(&(RelayM_OriginDataDemo[13].ctrl_status)))
    #define RELAYM_IO_14  ((uint32)*(&(RelayM_OriginDataDemo[14].ctrl_status)))
    #define RELAYM_IO_15  ((uint32)*(&(RelayM_OriginDataDemo[15].ctrl_status)))
#elif (RELAYM_MAX_NUM == 8)
    #define RELAYM_IO_0   ((uint32)*(&(RelayM_OriginDataDemo[0].ctrl_status)))
    #define RELAYM_IO_1   ((uint32)*(&(RelayM_OriginDataDemo[1].ctrl_status)))
    #define RELAYM_IO_2   ((uint32)*(&(RelayM_OriginDataDemo[2].ctrl_status)))
    #define RELAYM_IO_3   ((uint32)*(&(RelayM_OriginDataDemo[3].ctrl_status)))
    #define RELAYM_IO_4   ((uint32)*(&(RelayM_OriginDataDemo[4].ctrl_status)))
    #define RELAYM_IO_5   ((uint32)*(&(RelayM_OriginDataDemo[5].ctrl_status)))
    #define RELAYM_IO_6   ((uint32)*(&(RelayM_OriginDataDemo[6].ctrl_status)))
    #define RELAYM_IO_7   ((uint32)*(&(RelayM_OriginDataDemo[7].ctrl_status)))
#endif
*/

extern RelayM_ControlType RelayM_OriginDataDemo[RELAYM_MAX_NUM];      //继电器演示实际控制数据
extern RelayM_ControlType RelayM_CtrlData[RELAYM_MAX_NUM];      //继电器控制数据
//extern RelayM_ActureType RelayM_ActureData[RELAYM_MAX_NUM];           //继电器当前数据

#endif