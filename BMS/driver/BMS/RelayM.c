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
    RelayM_CtrlData[channel].ctrl_status = value;
}

uint32 RelayM_GetControl(uint8 channel)                 //��ȡ�̵���״̬
{
    return RelayM_CtrlData[channel].ctrl_status;
}

uint32 RelayM_GetActure(uint8 channel)                  //��ȡ�̵�����ǰ״̬
{
    return *RelayM_ActureData[channel].acture_status;
}

uint32 RelayM_GetOnTime(uint8 channel)                  //��ȡ�̵����պ�ʱ��
{
    return *RelayM_ActureData[channel].on_time;
}

void RelayM_SetOnTime(uint8 channel ,uint32 value)      //���ü̵����պ�ʱ��
{
    RelayM_CtrlData[channel].on_time = value;
}

uint32 RelayM_GetOffTime(uint8 channel)                 //��ȡ�̵����Ͽ�ʱ��
{
    return *RelayM_ActureData[channel].off_time;
}

void RelayM_SetOffTime(uint8 channel ,uint32 value)     //���ü̵����Ͽ�ʱ��
{
    RelayM_CtrlData[channel].off_time = value;
}

uint32 RelayM_GetRes(uint8 channel)                     //��ȡ�̵�������ֵ
{
    return *RelayM_ActureData[channel].res_value;
}

void RelayM_SetRes(uint8 channel ,uint32 value)         //���ü̵�������ֵ
{
    RelayM_CtrlData[channel].res_value = value;
}

RelayM_FaultStatusType RelayM_GetFault(uint8 channel)   //�̵������ϼ��
{
    RelayM_FaultStatusType rebuf;
    RelayM_InterruptOFF();
    if (RelayM_CtrlData[channel].ctrl_status == *RelayM_ActureData[channel].acture_status)//�жϼ̵�������״̬�͵�ǰ״̬�Ƿ�һ��
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

void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value) //���Ƽ̵���(Ŀ��ͨ��,����,ֵ��
{
    if (channel < RELAYM_MAX_NUM)                                                //����������
    {
        RelayM_InterruptOFF();
        switch (attribute)                                                       //�ж�����
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

uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute)             //�̵�����ǰ״̬��ȡ(ͨ��������)
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
