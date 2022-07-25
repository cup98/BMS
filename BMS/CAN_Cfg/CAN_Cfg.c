#include "CAN_Cfg.h"
#include "CAN.h"

#include "hidef.h"
#include "derivative.h"

int can_time = 0;

CAN_ConfigType can_hwcfg =			//è®¾ç½®æ³¢ç‰¹çŽ‡
{
	CAN_BPS_125K,
	1,
};

CAN_MsgType msg1 =					//è®¾ç½®CANæ ‡å‡†å¸§
{
	0x01F,
	0,
	0,
	{1,1,1,1,1,1,1,1},
	8,
	0,
};

CAN_MsgType msg2 =
{
	0x1FFFFFFF,
	1,
	0,
	{2,2,2,2,2,2,2,2},
	8,
	0,
};

CAN_MsgType msg3 =
{
	0x03,
	0,
	1,
	{3,3,3,3,3,3,3,3},
	8,
	0,
};

CAN_MsgType receive_buf =
{
	0xFF,
	0,
	0,
	{0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	8,
	0,
};


CAN_MsgType back_data_buf =
{
	0x111,
	0,
	0,
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	8,
	0,
};

void CAN1_GetToSend(void)									//璇诲嚭鎺ュ彈鍒扮殑鏁版嵁鍐嶅彂閫佸嚭鏉
{
  	if (CAN1_GetMsg(&receive_buf) == 1)
  	{
  	//	begin = 0;
      	if (CAN1_SendMsg(&receive_buf) == 1)
      	{
      	}
  	}
}

void CAN1_SendDemo(void)
{
	can_time++;
  	if (can_time == 1)
  	{
  	  	if (CAN1_SendMsg(&msg1) == 1)
  	  	{
  	  	}
  	}
  	else if (can_time == 2)
  	{
  	  	if (CAN1_SendMsg(&msg2) == 1)
  	  	{
  	  	}
  	}
 	else if (can_time == 3)
  	{
    	if (CAN1_SendMsg(&msg3) == 1)
    	{
    	}
    	can_time = 0;
  	}
	else
	{
	}
}

void CAN_GetToMsg_data(int byte_num ,unsigned char data)
{
	back_data_buf.data[byte_num] = data;
	CAN1_SendMsg(&back_data_buf);
}

/*void CAN_GetToMsg_data(CAN_MsgType receive_buf ,int byte_num ,unsigned char data)
{
	receive_buf.data[byte_num] = data;
}*/

/*CAN_MsgType CAN_CfgPreStateOut_Test =
{
	0x6F,
	0,
	0,
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	8,
	0,
};*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED						//CAN鎺ユ敹瑙﹀彂涓柇鍑芥暟
void interrupt VectorNumber_Vcan1rx CAN_receive(void)
{
    CAN1_GetToSend();
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG __NEAR_SEG NON_BANKED
void interrupt VectorNumber_Vpit0 PIT0(void)				//涓柇鏈嶅姟鍑芥暟
{
    PITTF_PTF0 = 1;
    //CAN1_SendDemo();										//PIT0涓柇
    //CAN1_GetToSend();
    
    
    Node_Poll();
}
#pragma CODE_SEG DEFAULT

