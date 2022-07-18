#include "Hv.h"

void Hv_Init(void)								//高压模块初始化
{

}
int Hv_Get(Hv_Voltage Hv_V_Object_Type)				//获取电压值
{
	int Voltage;
	if(Hv_V_Object_Type == Hv_BAT)					//返回BAT电压值
	{
		Voltage = Get_Hv_V_Type.BAT;			//返回获取的BAT电压值
	}
	else										//1:V1电压值
	{
		Voltage = Get_Hv_V_Type.V1;			//返回获取的V1电压值
	}
	return Voltage;
}