#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

int Pre_Cfg_Fault(void)                           //配置错误函数:0无错,1有错
{
	//return 0;
	return receive_buf.data[0];									//通过返回接收的CAN数字段0
}

int Pre_Cfg_Clock(void)                           //配置预充等待时间函数:单位秒，小于3秒
{
	//return 2;
	return receive_buf.data[1];                 //通过返回接收的CAN数字段1
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)		//获取目标电压
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


