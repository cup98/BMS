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
uint8 RelayM_SetContorl(uint8 channel ,uint32 value)     //设置继电器状态
{
    uint8 rebuf = 0;

    RELAYM_IO_(channel) = value;
    RelayM_CtrlData[channel].ctrl_status = value;
    rebuf = 1;
    return rebuf;
}

uint32 RelayM_GetControl(uint8 channel)                 //获取继电器状态
{
    return RelayM_CtrlData[channel].ctrl_status;
}

uint32 RelayM_GetActure(uint8 channel)                  //获取继电器当前状态
{
    return RELAYM_IO_(channel);
}

uint32 RelayM_GetOnTime(uint8 channel)                  //获取继电器闭合时间
{
    return RELAYM_ON_TIME_(channel);
}

uint8 RelayM_SetOnTime(uint8 channel ,uint32 value)      //设置继电器闭合时间
{
    uint8 rebuf = 0;

    RELAYM_ON_TIME_(channel) = value;
    RelayM_CtrlData[channel].on_time = value;
    rebuf = 1;
    return rebuf;
}

uint32 RelayM_GetOffTime(uint8 channel)                 //获取继电器断开时间
{
    return RELAYM_OFF_TIME_(channel);
}

uint8 RelayM_SetOffTime(uint8 channel ,uint32 value)     //设置继电器断开时间
{
    uint8 rebuf = 0;

    RELAYM_OFF_TIME_(channel) = value;
    RelayM_CtrlData[channel].off_time = value;
    rebuf = 1;
    return rebuf;
}

uint32 RelayM_GetRes(uint8 channel)                     //获取继电器内阻值
{
    return RELAYM_RES_VALUE_(channel);
}

uint8 RelayM_SetRes(uint8 channel ,uint32 value)         //设置继电器内阻值
{
    uint8 rebuf = 0;

    RELAYM_RES_VALUE_(channel) = value;
    RelayM_CtrlData[channel].res_value = value;
    rebuf = 1;
    return rebuf;
}

RelayM_FaultStatusType RelayM_GetFault(uint8 channel)   //继电器故障检测
{
    RelayM_FaultStatusType rebuf = 0;

    if (channel < RELAYM_MAX_NUM)
    {
        if ((RelayM_CtrlData[channel].ctrl_status) == (RELAYM_IO_(channel)))//判断继电器控制状态和当前状态是否一致
        {
            rebuf = (RelayM_FaultStatusType)RELAYM_NORMAL;
        }
        else if ((RelayM_CtrlData[channel].ctrl_status == 1) && (RELAYM_IO_(channel)))
        {
            rebuf = (RelayM_FaultStatusType)RELAYM_ADHESION;
        }
        else if ((RelayM_CtrlData[channel].ctrl_status == 0) && (RELAYM_IO_(channel)))
        {
            rebuf = (RelayM_FaultStatusType)RELAYM_OPEN_LOOP;
        }
        else
        {
        }
    }
    return rebuf;
}

uint8 (*RelayM_Set[])(uint8 ,uint32) = {RelayM_SetContorl ,
                                        RelayM_SetOnTime ,
                                        RelayM_SetOffTime ,
                                        RelayM_SetRes};

uint8 RelayM_Control(uint8 channel ,RelayM_CtrlAttributeType attribute ,uint32 value) //控制继电器(目标通道,属性,值）
{
    uint8 rebuf = 0;

    if (channel < RELAYM_MAX_NUM)
    {
        if (RelayM_Set[attribute](channel ,value))
        {
        }
    }
    rebuf = 1;
    return rebuf;
}

uint32 (*RelayM_Get[])(uint8) = {RelayM_GetControl ,
                                 RelayM_GetActure ,
                                 RelayM_GetOnTime ,
                                 RelayM_GetOffTime ,
                                 RelayM_GetRes};

uint32 RelayM_Acture(uint8 channel ,RelayM_ActureAttributeType attribute) //继电器当前状态获取(通道，属性)
{
    uint8 rebuf = 0;

    if (channel < RELAYM_MAX_NUM)
    {
        return RelayM_Get[attribute](channel);
    }
    rebuf = 1;
    return rebuf;
}

/*void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value) //控制继电器(目标通道,属性,值）
{
    switch (attribute)                                                       //判断属性
    {
        case RELAYM_CTRL_STATUS:
        {
            RelayM_SetContorl(channel ,value);
        } break;

        case RELAYM_CTRL_ON_TIME:
        {
            #if (RELAYM_ON_TIME_SET_SUPPORT == TRUE)
                RelayM_SetOnTime(channel ,value);
            #endif
        } break;

        case RELAYM_CTRL_OFF_TIME:
        {
            #if (RELAYM_OFF_TIME_SET_SUPPORT == TRUE)
                RelayM_SetOffTime(channel ,value);
            #endif
        } break;

        case RELAYM_CTRL_RES_VALUE:
        {
            #if (RELAYM_RES_VALUE_SET_SUPPORT == TRUE)
                RelayM_SetRes(channel ,value);
            #endif
        } break;
    }
}

uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute)             //继电器当前状态获取(通道，属性)
{
    uint32 rebuf ;
    if (channel < RELAYM_MAX_NUM)
    {
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
    }
    return rebuf;
}*/
