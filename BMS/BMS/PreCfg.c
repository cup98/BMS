#include "PreCfg.h"
#include "CAN_Cfg.h"

int PreCfg_Fault(void)
{
  return 0;										//举例故障为无

}

int PreCfg_Clock(void)
{
	return 2;
}

PreCfg_Get_HvVoltageType PerCfg_GetVoltageType =					//举例电压值
{
	90,							//BAT电压为90.0V
	91,							//V1电压为91.0V
};
