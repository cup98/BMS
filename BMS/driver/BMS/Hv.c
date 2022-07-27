#include "Hv.h"
#include "Pre_Cfg.h"

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
	else if (object == V1)								//选中V1
	{
		rebuf = Per_Cfg_GetVoltage(V1);	//返回V1电压
	}
	else if (object == V2)								//选中V2
	{
		rebuf = Per_Cfg_GetVoltage(V2);	//返回V1电压
	}
	else if (object == V3)								//选中V3
	{
		rebuf = Per_Cfg_GetVoltage(V3);	//返回V1电压
	}
	else
	{
	}
	return rebuf;
}