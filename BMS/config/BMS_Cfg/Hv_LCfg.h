#ifndef __HV_LCFG_H
#define __HV_LCFG_H

#include "hidef.h"
#include "derivative.h"
#include "Hv.h"

#define HV_MAX_NUM 9

#define HV_VOLTAGE_MIN  (10U)
#define HV_CURRENT_MIN  (10U)
#define HV_TEMP_MIN     (10U)
#define HV_VOLTAGE_MAX  (100U)
#define HV_CURRENT_MAX  (100U)
#define HV_TEMP_MAX     (100U)

extern Hv_DataType Hv_DemoData[HV_MAX_NUM];

#endif