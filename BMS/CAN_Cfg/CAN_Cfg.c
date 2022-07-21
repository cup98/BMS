#include "CAN_Cfg.h"
#include "CAN.h"

#include "hidef.h"
#include "derivative.h"

int CAN_Time = 0;

extern int begin;
void CAN1_GetToSend(void)									  //璇诲嚭鎺ュ彈鍒扮殑鏁版嵁鍐嶅彂閫佸嚭鏉
{
  	if (CAN1_GetMsg(&CAN1_GetBufType) == 1)
  	{
  		begin = 0;
      	if (CAN1_SendMsg(&CAN1_GetBufType) == 1)
      	{
      	}
  	}
}

void CAN1_SendDemo(void)
{
	CAN_Time++;

  	if (CAN_Time == 1)
  	{
  	  	if (CAN1_SendMsg(&CAN_CfgMsg1Type) == 1)
  	  	{
  	  	}
  	}
  	else if (CAN_Time == 2)
  	{
  	  	if (CAN1_SendMsg(&CAN_CfgMsg2Type) == 1)
  	  	{
  	  	}
  	}
 	else if (CAN_Time == 3)
  	{
    	if (CAN1_SendMsg(&CAN_CfgMsg3Type) == 1)
    	{
    	}
    	CAN_Time = 0;
  	}
	else
	{
	}
}

CAN_MsgType CAN_CfgMsg1Type =					//è®¾ç½®CANæ ‡å‡†å¸§
{
	0x01F,
	0,
	0,
	{1,1,1,1,1,1,1,1},
	8,
	0,
};

CAN_MsgType CAN_CfgMsg2Type =
{
	0x1FFFFFFF,
	1,
	0,
	{2,2,2,2,2,2,2,2},
	8,
	0,
};

CAN_MsgType CAN_CfgMsg3Type =
{
	0x03,
	0,
	1,
	{3,3,3,3,3,3,3,3},
	8,
	0,
};

CAN_MsgType CAN_CfgPreStateOut_TestType =
{
	0x6F,
	0,
	0,
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	8,
	0,
};

CAN_ConfigType CAN_CfgHwType =			//è®¾ç½®æ³¢ç‰¹çŽ‡
{
	CAN_BPS_125K,
	1,
};
