#ifndef __HV_H
#define __HV_H

#include "hidef.h"
#include "derivative.h"

typedef enum _Hv_Voltage_Type 				//��ȡ��ѹĿ��
{
	BAT,
	V1,
} Hv_Voltage_Type;

extern void Hv_Init(void); 					//��ѹ����ģ���ɳ�ʼ������
extern int Hv_Get(Hv_Voltage_Type object);	//��ȡ��ѹ����

#endif