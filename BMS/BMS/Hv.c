#include "Hv.h"
#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

void Hv_Init(void)						//高压管理模块由初始化函数
{
}

int Hv_Get(Hv_Voltage_Type object)		//获取电压函数
{
	int rebuf = 0;
	if(object == BAT)					//选中Bat
	{
		rebuf = Per_Cfg_GetVoltage(BAT);//返回BAT电压
	}
	else								//选中V1
	{
		rebuf = Per_Cfg_GetVoltage(V1);	//返回V1电压
	}
	return rebuf;
}