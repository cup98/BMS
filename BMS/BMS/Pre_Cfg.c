#include "Pre_Cfg.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

int Pre_Cfg_Fault(void)
{
	return CAN1_GetBufType.Data[0];										//举例故障为无:0
}

int Pre_Cfg_Clock(void)
{
	return CAN1_GetBufType.Data[1];
}

Pre_Cfg_GetHvVoltageType Per_Cfg_GetVoltageType =					//举例电压值
{
	100,							//BAT电压为90.0V
	100,							//V1电压为91.0V
};



