#include "RelayM.h"
#include "RelayM_LCfg.h"

void RelayM_Init(void)                                   //继电器模块由初始化函数
{

}

void RelayM_InterruptON(void)                           //开中断
{

}

void RelayM_InterruptOFF(void)                          //关中断
{

}
void RelayM_SetContorl(uint8 channel ,uint32 value)     //设置继电器状态
{
    RelayM_CtrlData[channel].ctrl_status = value;
}

uint32 RelayM_GetControl(uint8 channel)                 //获取继电器状态
{
    return RelayM_CtrlData[channel].ctrl_status;
}

uint32 RelayM_GetActure(uint8 channel)                  //获取继电器当前状态
{
    return *RelayM_ActureData[channel].acture_status;
}

uint32 RelayM_GetOnTime(uint8 channel)                  //获取继电器闭合时间
{
    return *RelayM_ActureData[channel].on_time;
}

void RelayM_SetOnTime(uint8 channel ,uint32 value)      //设置继电器闭合时间
{
    RelayM_CtrlData[channel].on_time = value;
}

uint32 RelayM_GetOffTime(uint8 channel)                 //获取继电器断开时间
{
    return *RelayM_ActureData[channel].off_time;
}

void RelayM_SetOffTime(uint8 channel ,uint32 value)     //设置继电器断开时间
{
    RelayM_CtrlData[channel].off_time = value;
}

uint32 RelayM_GetRes(uint8 channel)                     //获取继电器内阻值
{
    return *RelayM_ActureData[channel].res_value;
}

void RelayM_SetRes(uint8 channel ,uint32 value)         //设置继电器内阻值
{
    RelayM_CtrlData[channel].res_value = value;
}

RelayM_FaultStatusType RelayM_GetFault(uint8 channel)   //继电器故障检测
{
    RelayM_FaultStatusType rebuf;
    RelayM_InterruptOFF();
    if (RelayM_CtrlData[channel].ctrl_status == *RelayM_ActureData[channel].acture_status)//判断继电器控制状态和当前状态是否一致
    {
        rebuf = (RelayM_FaultStatusType)RELAYM_NORMAL;
    }
    else if ((RelayM_CtrlData[channel].ctrl_status == 1) && (*RelayM_ActureData[channel].acture_status == 0))
    {
        rebuf = (RelayM_FaultStatusType)RELAYM_ADHESION;
    }
    else if ((RelayM_CtrlData[channel].ctrl_status == 0) && (*RelayM_ActureData[channel].acture_status == 1))
    {
        rebuf = (RelayM_FaultStatusType)RELAYM_OPEN_LOOP;
    }
    else
    {
    }
    RelayM_InterruptON();
    return rebuf;
}

void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value) //控制继电器(目标通道,属性,值）
{
    if (channel < RELAYM_MAX_NUM)                                                //数组溢出检测
    {
        RelayM_InterruptOFF();
        switch (attribute)                                                       //判断属性
        {
            case RELAYM_CTRL_STATUS:
            {
                RelayM_SetContorl(channel ,value);
            } break;

            case RELAYM_CTRL_ON_TIME:
            {
                RelayM_SetOnTime(channel ,value);
            } break;

            case RELAYM_CTRL_OFF_TIME:
            {
                RelayM_SetOffTime(channel ,value);
            } break;

            case RELAYM_CTRL_RES_VALUE:
            {
                RelayM_SetRes(channel ,value);
            } break;
        }
        RelayM_InterruptON();
    }
}

uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute)             //继电器当前状态获取(通道，属性)
{
    uint32 rebuf ;
    if (channel < RELAYM_MAX_NUM)
    {
        RelayM_InterruptOFF();
        switch (attribute)
        {
            case RELAYM_ACTURE_CONTROL:
            {
                rebuf = RelayM_GetControl(channel);
            } break;

            case RELAYM_ACTURE_STATUS:
            {
                rebuf = RelayM_GetActure(channel);
            } break;

            case RELAYM_ACTURE_ON_TIME:
            {
                rebuf = RelayM_GetOnTime(channel);
            } break;

            case RELAYM_ACTURE_OFF_TIME:
            {
                rebuf = RelayM_GetOffTime(channel);
            } break;

            case RELAYM_ACTURE_RES_VALUE:
            {
                rebuf = RelayM_GetRes(channel);
            } break;
        }
        RelayM_InterruptON();
    }
    return rebuf;
}
