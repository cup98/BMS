#include "RelayM.h"
#include "RelayM_LCfg.h"

void RelayM_Init(void)                                   //�̵���ģ���ɳ�ʼ������
{

}

void RelayM_InterruptON(void)                           //���ж�
{

}

void RelayM_InterruptOFF(void)                          //���ж�
{

}
void RelayM_SetContorl(uint8 channel ,uint32 value)     //���ü̵���״̬
{
    RELAYM_IO_(channel) = value;
    RelayM_CtrlData[channel].ctrl_status = value;
}

uint32 RelayM_GetControl(uint8 channel)                 //��ȡ�̵���״̬
{
    return RelayM_CtrlData[channel].ctrl_status;
}

uint32 RelayM_GetActure(uint8 channel)                  //��ȡ�̵�����ǰ״̬
{
    return RELAYM_IO_(channel);
}

uint32 RelayM_GetOnTime(uint8 channel)                  //��ȡ�̵����պ�ʱ��
{
    return RELAYM_ON_TIME_(channel);
}

void RelayM_SetOnTime(uint8 channel ,uint32 value)      //���ü̵����պ�ʱ��
{
    RELAYM_ON_TIME_(channel) = value;
    RelayM_CtrlData[channel].on_time = value;
}

uint32 RelayM_GetOffTime(uint8 channel)                 //��ȡ�̵����Ͽ�ʱ��
{
    return RELAYM_OFF_TIME_(channel);
}

void RelayM_SetOffTime(uint8 channel ,uint32 value)     //���ü̵����Ͽ�ʱ��
{
    RELAYM_OFF_TIME_(channel) = value;
    RelayM_CtrlData[channel].off_time = value;
}

uint32 RelayM_GetRes(uint8 channel)                     //��ȡ�̵�������ֵ
{
    return RELAYM_RES_VALUE_(channel);
}

void RelayM_SetRes(uint8 channel ,uint32 value)         //���ü̵�������ֵ
{
    RELAYM_RES_VALUE_(channel) = value;
    RelayM_CtrlData[channel].res_value = value;
}

RelayM_FaultStatusType RelayM_GetFault(uint8 channel)   //�̵������ϼ��
{
    RelayM_FaultStatusType rebuf;
    if ((RelayM_CtrlData[channel].ctrl_status) == (RELAYM_IO_(channel)))//�жϼ̵�������״̬�͵�ǰ״̬�Ƿ�һ��
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
    return rebuf;
}

void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value) //���Ƽ̵���(Ŀ��ͨ��,����,ֵ��
{
    switch (attribute)                                                       //�ж�����
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

uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute)             //�̵�����ǰ״̬��ȡ(ͨ��������)
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
}
