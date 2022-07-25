#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

int Pre_Cfg_Fault(void)                           //���ô�����:0�޴�,1�д�
{
	//return 0;
	return receive_buf.data[0];									//ͨ�����ؽ��յ�CAN���ֶ�0
}

int Pre_Cfg_Clock(void)                           //����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
{
	//return 2;
	return receive_buf.data[1];                 //ͨ�����ؽ��յ�CAN���ֶ�1
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)		//��ȡĿ���ѹ
{
    int rebuf = 0;
    if (object == BAT)
    {
        //rebuf = 50;
        rebuf = receive_buf.data[2];
    }
    else if (object == V1)
    {
        rebuf = 100;
    }
    else if (object == V2)
    {
        rebuf = 120;
    }
    else if (object == V3)
    {
        rebuf = 140;
    }
    else
    {
    }
    return rebuf;
}

Pre_Cfg_IsFailType pre_cfg_max_time =
{
    3,
};

Pre_Cfg_IsFinishType pre_cfg_voltage_stats =
{
    V1,
    95,
};


