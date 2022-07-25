#include "CAN.h"
#include "CAN_Cfg.h"

int wait_time = 100;				//ϵͳ�ȴ�ʱ��

void CAN_Init(void)											//CAN初始�
{
	CAN1_Init(&can_hwcfg);
}

void CAN1_Init(CAN_ConfigType *can_cfg)						//CAN1初始化以及配置CLK
{
	int wait_1 = 0,wait_2 = 0,wait_3 = 0;
	if (CAN1CTL0_INITRQ == 0) 								//查询是否进入初始化状�
	{
		CAN1CTL0_INITRQ = 1;								//进入初始化状�
	}
	while (CAN1CTL1_INITAK == 0 && wait_1 < wait_time)		//等待进入初始化状�
	{
		wait_1++;
	}
	CAN1BTR0_SJW = 0;										//设置同步
	if (can_cfg->sp == 1)									//����
	{
		CAN0BTR1_SAMP = 0;
	}
	else
	{
		CAN0BTR1_SAMP = 1;
	}
	switch (can_cfg->bps)
	{
		case CAN_BPS_20K:
		{
			CAN1BTR0_BRP = 0x3F;
			CAN1BTR1 |= 0x7F;
		} break;

		case CAN_BPS_50K:
		{
			CAN1BTR0_BRP = 0x1C;
			CAN1BTR1 |= 0x4F;
		} break;

		case CAN_BPS_100K:
		{
			CAN1BTR0_BRP = 0x0F;
			CAN1BTR1 |= 0x2F;
		} break;

		case CAN_BPS_125K:
		{
			CAN1BTR0_BRP = 0x0E;
			CAN1BTR1 |= 0x1D;
		} break;

		case CAN_BPS_250K:
		{
			CAN1BTR0_BRP = 0x07;
			CAN1BTR1 |= 0x1C;
		} break;

		case CAN_BPS_500K:
		{
			CAN1BTR0_BRP = 0x03;
			CAN1BTR1 |= 0x1C;
		} break;

		case CAN_BPS_800K:
		{
			CAN1BTR0_BRP = 0x01;
			CAN1BTR1 |= 0x2F;
		} break;

		case CAN_BPS_1000K:
		{
			CAN1BTR0_BRP = 0x01;
			CAN1BTR1 |= 0x1C;
		} break;
	}
	CAN1IDMR0 = 0xFF;										//关闭滤波�
	CAN1IDMR1 = 0xFF;
	CAN1IDMR2 = 0xFF;
	CAN1IDMR3 = 0xFF;
	CAN1IDMR4 = 0xFF;
	CAN1IDMR5 = 0xFF;
	CAN1IDMR6 = 0xFF;
	CAN1IDMR7 = 0xFF;
	CAN1CTL1  = 0xC0;										//使能MSCAN模块,设置为一般运行模式�使用�线时钟�
	CAN1CTL0  = 0x00;										//返回�般模式运�
	while (CAN1CTL1_INITAK && wait_2 < wait_time)			//等待回到�般运行模�
	{
		wait_2++;
	}
	while ((CAN1CTL0_SYNCH == 0) && wait_3 < wait_time) 		//等待总线时钟同步
	{
		wait_3++;
	}
	CAN1RIER_RXFIE = 1;										//禁止接收中断
}
															//CAN1发�
int CAN1_SendMsg(CAN_MsgType *can_msg)
{
	unsigned char send_buf, sp ,rebuf;						//设置发�缓冲区、发送数据位�
	if (can_msg->len > CAN_MSG_MAXLEN)						//�查数据长�
	{
		rebuf = 0;
	}
	if (CAN1CTL0_SYNCH == 0)								//�查�线时钟
	{
		rebuf = 0;
	}
	do
	{
		CAN1TBSEL = CAN1TFLG;
		send_buf  = CAN1TBSEL;
	} while (!(send_buf));									//寻找空闲的缓冲器														//��չ֡ID����
	if (can_msg->IDE)
	{
  		CAN1TXIDR0 =  (unsigned char)(can_msg->id >> 21);
  		CAN1TXIDR1 =  (unsigned char)(can_msg->id >> 13) & 0xE0;
  		CAN1TXIDR1 |= 0x18;
  		CAN1TXIDR1 |= (unsigned char)(can_msg->id >> 15) & 0x07;
  		CAN1TXIDR2 =  (unsigned char)(can_msg->id >> 7);
  		CAN1TXIDR3 =  (unsigned char)(can_msg->id << 1);
  		if (can_msg->RTR)									//判断IDE�0标准�,1远程�
		{
			CAN1TXIDR3 |= 0x01;
		}
		else
		{
			CAN1TXIDR3 &= 0xFE;
		}
	}
	else
	{														//��׼֡ID����
  		CAN1TXIDR0 =  (unsigned char)(can_msg->id >> 3);
  		CAN1TXIDR1 =  (unsigned char)(can_msg->id << 5);
  		CAN1TXIDR1 &= 0xF7;
  		if (can_msg->RTR)									//判断IDE�0标准�,1远程�
		{
			CAN1TXIDR1 |= 0x10;
		}
		else
		{
			CAN1TXIDR1 &= 0xEF;
		}
	}
	for (sp = 0 ; sp < can_msg->len ; sp++)					//依次将数据写入寄存器
	{
		*((&CAN1TXDSR0) + sp) = can_msg->data[sp];
	}
	CAN1TXDLR  = can_msg->len;								//写入数据长度
	CAN1TXTBPR = can_msg->prty;								//写入优先�
	CAN1TFLG   = send_buf;									//清TXx标志(缓冲器准备发�)
	rebuf = 1;
	return rebuf;
}

int CAN1_GetMsg(CAN_MsgType *can_msg)						//CAN1接收
{
  	unsigned char sp ,rebuf;								//设置接收数据位数
  	if (!(CAN1RFLG_RXF))									//�测接收标�
  	{
  		rebuf = 0;
  	}
  	if ((CAN1RXIDR1 & 0x08) == 0x08)                        //判断是否为标准帧
  	{
        can_msg->id = ((unsigned long)(CAN1RXIDR0 & 0xff)) << 21;
  	    can_msg->id = can_msg->id | (((unsigned long)(CAN1RXIDR1 & 0xe0)) << 13);
	    can_msg->id = can_msg->id | (((unsigned long)(CAN1RXIDR1 & 0x07)) << 15);
	    can_msg->id = can_msg->id | (((unsigned long)(CAN1RXIDR2 & 0xff)) << 7);
	    can_msg->id = can_msg->id | (((unsigned long)(CAN1RXIDR3 & 0xfe)) >> 1);
        can_msg->IDE = 1;
        if (CAN1RXIDR3 & 0x01)                         		//判断是否为远程帧
  		{
  	  		can_msg->RTR = 1;
  		}
  		else
  		{
  	  		can_msg->RTR = 0;
 		}
  	}
  	else
  	{
  	  	can_msg->id  = (unsigned long)(CAN1RXIDR0 << 3) | 	//读出接收帧ID�8�
            	  	   (unsigned long)(CAN1RXIDR1 >> 5) ; 	//并且与上读出接收帧ID�3�
        can_msg->IDE = 0;
        if (CAN1RXIDR1 & 0x10)                         		//判断是否为远程帧
  		{
  	  		can_msg->RTR = 1;
  		}
  		else
  		{
  	  		can_msg->RTR = 0;
 		}
 	}
  	can_msg->len = CAN1RXDLR;						  		//读出接收的数据长�
  	for (sp = 0; sp < can_msg->len; sp++)			  		//依次读出接收的每�位数�
  	{
  		can_msg->data[sp] = *((&CAN1RXDSR0) + sp);
  	}
  	CAN1RFLG |= 1;											//清RXF标志�(缓冲器准备接�)
    rebuf = 1;
  	return rebuf;
}

void CAN_Delay10ms(unsigned int i)							//延时
{
    unsigned int n,m;
    for (n=0; n<250; n++)
    {
        for (m=0; m<(80*i); m++)
        {
        }
    }
}


