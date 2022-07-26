#include "CAN_Cfg.h"
#include "Pre_Cfg.h"
#include "Node.h"

int CAN_Time = 0;

CAN_ConfigType CAN_HwCfg =			//è®¾ç½®æ³¢ç‰¹çŽ‡
{
	CAN_BPS_125K,
	1,
};

CAN_MsgType Msg1 =					//è®¾ç½®CANæ ‡å‡†å¸§
{
	0x01F,
	0,
	0,
	{1,1,1,1,1,1,1,1},
	8,
	0,
};

CAN_MsgType Msg2 =
{
	0x1FFFFFFF,
	1,
	0,
	{2,2,2,2,2,2,2,2},
	8,
	0,
};

CAN_MsgType Msg3 =
{
	0x03,
	0,
	1,
	{3,3,3,3,3,3,3,3},
	8,
	0,
};

CAN_MsgType CAN_Cfg_ReceiveBuf =
{
	0x5FF,
	0,
	0,
	{0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	8,
	0,
};


CAN_MsgType CAN_Cfg_BackDataBuf =
{
	0x111,
	0,
	0,
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	8,
	0,
};

void CAN1_SendDemo(void)
{
	CAN_Time++;
  	if (CAN_Time == 1)
  	{
  	  	if (CAN1_SendMsg(&Msg1) == 1)
  	  	{
  	  	}
  	}
  	else if (CAN_Time == 2)
  	{
  	  	if (CAN1_SendMsg(&Msg2) == 1)
  	  	{
  	  	}
  	}
 	else if (CAN_Time == 3)
  	{
    	if (CAN1_SendMsg(&Msg3) == 1)
    	{
    	}
    	CAN_Time = 0;
  	}
	else
	{
	}
}

void CAN_Get_PreCfg(void)									//璇诲嚭鎺ュ彈鍒扮殑鏁版嵁鍐嶅彂閫佸嚭鏉
{
  	if (CAN1_GetMsg(&CAN_Cfg_ReceiveBuf) == 1)
  	{
      	Pre_Cfg_WriteCfg(FAULT ,CAN_Cfg_ReceiveBuf.data[0]);
      	Pre_Cfg_WriteCfg(CLOCK ,CAN_Cfg_ReceiveBuf.data[1]);
      	Pre_Cfg_WriteCfg(PRE_VOLTAGE ,CAN_Cfg_ReceiveBuf.data[2]);
      	if (CAN1_SendMsg(&CAN_Cfg_ReceiveBuf) == 1)
      	{
      	}
  	}
}

void CAN_Send_PreNodeState(void)
{
	CAN_Cfg_BackDataBuf.data[0] = (unsigned char)Node_BackNodeState(CURRENT_NODE);
	CAN_Cfg_BackDataBuf.data[1] = (unsigned char)Node_BackNodeState(NEXT_NODE);
	CAN_Cfg_BackDataBuf.data[7] = (unsigned char)Node_BackNodeState(BRANCH_NUM);
  if (CAN1_SendMsg(&CAN_Cfg_BackDataBuf) == 1)
 	{
  }
}

#pragma CODE_SEG __NEAR_SEG NON_BANKED						//CAN鎺ユ敹瑙﹀彂涓柇鍑芥暟
void interrupt VectorNumber_Vcan1rx CAN_receive(void)
{
    CAN_Get_PreCfg();
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG __NEAR_SEG NON_BANKED
void interrupt VectorNumber_Vpit0 PIT0(void)				//涓柇鏈嶅姟鍑芥暟
{
    PITTF_PTF0 = 1;
    CAN_Send_PreNodeState();
    Node_Poll();
}
#pragma CODE_SEG DEFAULT

