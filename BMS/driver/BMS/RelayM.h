#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"

typedef enum _RelayM_Object_Type   		//�����̵�������Ŀ��
{
	MASTER,
	PRECHANG,
} RelayM_Object_Type;

typedef struct _RelayM_CtrlType			//�̵���Ŀ��״̬
{
	int Master;							//�����̵���
	int Precharge;						//Ԥ��̵���
} RelayM_CtrlType;

typedef struct _RelayM_SwitchType		//����Ŀ��״̬
{
	int Master;							//��������
	int Precharge;						//Ԥ�俪��
} RelayM_SwitchType;

extern void RelayM_Init(void);										//�̵���ģ���ɳ�ʼ������
extern void RelayM_Control(RelayM_Object_Type object ,int state);	//���Ƽ̵������غ���,���Ƽ̵������غ���(����Ŀ��,״̬)
extern void RelayM_Change(RelayM_Object_Type object ,int state);	//�л����غ���,�л����غ���(����Ŀ��,״̬)

#endif