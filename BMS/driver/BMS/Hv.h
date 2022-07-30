#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

typedef unsigned char      uint8;
typedef unsigned short int uint16;
typedef unsigned int       uint32;

typedef enum _Hv_ChannelType            //通道
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

typedef enum _Hv_AttributeType          //属性类型
{
    HV_VOLTAGE,
    HV_CURRENT,
    HV_TEMP,
    HV_CHARGE,
    HV_DISCHARGE,
} Hv_AttributeType;

typedef struct _Hv_DataType             //高压数据类型
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
