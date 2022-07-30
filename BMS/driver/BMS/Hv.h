#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

#define HV_MAX_NUM 9

#define HV_VOLTAGE_MIN  (10U)
#define HV_CURRENT_MIN  (10U)
#define HV_TEMP_MIN     (10U)
#define HV_VOLTAGE_MAX (100U)
#define HV_CURRENT_MAX  (100U)
#define HV_TEMP_MAX      (100U)

typedef unsigned char      uint8;
typedef unsigned short int uint16;
typedef unsigned int       uint32;

typedef enum _Hv_ChannelType
{
    HV_CHANNEL_0,
    HV_CHANNEL_1,
    HV_CHANNEL_2,
    HV_CHANNEL_3,
    HV_CHANNEL_4,
    HV_CHANNEL_5,
    HV_CHANNEL_6,
    HV_CHANNEL_7,
    HV_CHANNEL_8,
} Hv_ChannelType;

typedef enum _Hv_AttributeType
{
    HV_VOLTAGE,
    HV_CURRENT,
    HV_TEMP,
    HV_CHARGE,
    HV_DISCHARGE,
} Hv_AttributeType;

typedef struct _Hv_DataType
{
    Hv_ChannelType channel;
    uint32 voltage;
    uint32 current;
    uint32 temp;
} Hv_DataType;

extern void Hv_Init(void);                  //高压管理模块由初始化函数
void Hv_InterruptON();
void Hv_InterruptOFF();
int Hv_RangeOut(uint32 data ,Hv_AttributeType attribute);
uint32 Hv_GetAttribute(Hv_ChannelType object ,Hv_AttributeType attribute);
extern uint32 Hv_Get(Hv_ChannelType object ,Hv_AttributeType attribute);  //获取电压函数
extern Hv_AttributeType Hv_BatteryStats(Hv_ChannelType object);

#endif
