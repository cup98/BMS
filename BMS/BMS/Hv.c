#include "Hv.h"
#include "Pre_Cfg.h"
#include "CAN_Cfg.h"

void Hv_Init(void)								//高压模块初始化
{

}
int Hv_Get(Hv_Voltage_Type object)				//获取电压值
{
	if(object == BAT)					//返回BAT电压值
	{
		return Per_Cfg_GetVoltageType.BAT;			//返回获取的BAT电压值
	}
	else										//1:V1电压值
	{
		return Per_Cfg_GetVoltageType.V1;			//返回获取的V1电压值
	}
}