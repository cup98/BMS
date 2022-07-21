#ifndef __PRE_CFG_H
#define __PRE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"
#include "CAN.h"
#include "Hv.h"

extern const unsigned char Node_Num;

extern int Pre_Cfg_Fault(void);							//���ô�����:0�޴�,1�д�
extern int Pre_Cfg_Clock(void);							//����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
extern int Per_Cfg_GetVoltage(Hv_Voltage_Type object);	//��ȡĿ���ѹ(Ŀ��BAT/V1)
extern Node_StateType Pre_Cfg_NodeStateType[];

#endif