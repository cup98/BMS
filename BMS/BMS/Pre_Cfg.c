#include "Pre_Cfg.h"

int Pre_Cfg_Fault(void)                           //���ô�����:0�޴�,1�д�
{
	return CAN1_GetBufType.Data[0];									//ͨ�����ؽ��յ�CAN���ֶ�0
}

int Pre_Cfg_Clock(void)                           //����Ԥ��ȴ�ʱ�亯��:��λ�룬С��3��
{
	return CAN1_GetBufType.Data[1];                 //ͨ�����ؽ��յ�CAN���ֶ�1
}

int Per_Cfg_GetVoltage(Hv_Voltage_Type object)		//��ȡĿ���ѹ
{
  int ref = 0;
  if (object == BAT)
  {
    ref = CAN1_GetBufType.Data[2];
  }
  else
  {
    ref = 100;
  }
  return ref;
}

Node_StateType Pre_Cfg_NodeStateType[] =         //�ڵ�״̬ת����
{
 		{Node0 ,Pre_Cfg_Fault ,1 ,No_Act ,Node0 },
 		{Node0 ,Pre_Cfg_Fault ,0 ,PrechargeM_StartPre ,Node1 },
 		{Node1 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopPre ,Node0 },
 		{Node1 ,PrechargeM_IsFail ,1 ,PrechargeM_StopPre ,Node0 },
 		{Node1 ,PrechargeM_IsFinish ,1 ,PrechargeM_Change ,Node2 },
 		{Node1 ,PrechargeM_IsFinish ,0 ,No_Act ,Node1 },
 		{Node2 ,Pre_Cfg_Fault ,1 ,PrechargeM_StopMaster ,Node0 },
 		{Node2 ,Pre_Cfg_Fault ,0 ,No_Act ,Node2 },
};

const unsigned char Node_Num = sizeof(Pre_Cfg_NodeStateType)/sizeof(Pre_Cfg_NodeStateType[0]);//��ȡ�ڵ�״̬����
