#include "CAN.h"
#include "CAN_LCfg.h"

void CAN_Init(void)                                         //CANåˆå§‹åŒ
{
    CAN1_Init(&CAN_HwCfg);
}

void CAN1_Init(CAN_ConfigType *can_cfg)                     //CAN1åˆå§‹åŒ–ä»¥åŠé…ç½®CLK
{
    int wait_time = 100;                                    //ÏµÍ³µÈ´ýÊ±¼ä
    int wait_1 = 0 ,wait_2 = 0 ,wait_3 = 0;

    if (CAN1CTL0_INITRQ == 0)                               //æŸ¥è¯¢æ˜¯å¦è¿›å…¥åˆå§‹åŒ–çŠ¶æ€
    {
        CAN1CTL0_INITRQ = 1;                                //è¿›å…¥åˆå§‹åŒ–çŠ¶æ€
    }
    while (CAN1CTL1_INITAK == 0 && wait_1 < wait_time)      //ç­‰å¾…è¿›å…¥åˆå§‹åŒ–çŠ¶æ€
    {
        wait_1++;
    }
    CAN1BTR0_SJW = 0;                                       //è®¾ç½®åŒæ­¥
    if (can_cfg->sp == 1)                                   //²ÉÑù
    {
        CAN1BTR1_SAMP = 0;
    }
    else
    {
        CAN1BTR1_SAMP = 1;
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

        default:
        {
        } break;
    }
    CAN1IDMR0 = 0xFF;                                       //å…³é—­æ»¤æ³¢å™
    CAN1IDMR1 = 0xFF;
    CAN1IDMR2 = 0xFF;
    CAN1IDMR3 = 0xFF;
    CAN1IDMR4 = 0xFF;
    CAN1IDMR5 = 0xFF;
    CAN1IDMR6 = 0xFF;
    CAN1IDMR7 = 0xFF;
    CAN1CTL1  = 0xC0;                                       //ä½¿èƒ½MSCANæ¨¡å—,è®¾ç½®ä¸ºä¸€èˆ¬è¿è¡Œæ¨¡å¼ãä½¿ç”¨æ»çº¿æ—¶é’Ÿæº
    CAN1CTL0  = 0x00;                                       //è¿”å›žä¸èˆ¬æ¨¡å¼è¿è¡
    while (CAN1CTL1_INITAK && wait_2 < wait_time)           //ç­‰å¾…å›žåˆ°ä¸èˆ¬è¿è¡Œæ¨¡å¼
    {
        wait_2++;
    }
    while ((CAN1CTL0_SYNCH == 0) && wait_3 < wait_time)         //ç­‰å¾…æ€»çº¿æ—¶é’ŸåŒæ­¥
    {
        wait_3++;
    }
    CAN1RIER_RXFIE = 1;                                     //ç¦æ­¢æŽ¥æ”¶ä¸­æ–­
}
                                                            //CAN1å‘é
int CAN1_SendMsg(CAN_MsgType *can_msg)
{
    unsigned char send_buf = 0 ,sp = 0 ,rebuf = 0;                      //è®¾ç½®å‘éç¼“å†²åŒºã€å‘é€æ•°æ®ä½æ•

    if ((can_msg->len > CAN_MSG_MAXLEN) && (!CAN1CTL0_SYNCH))                      //æ£æŸ¥æ•°æ®é•¿åº
    {
        rebuf = 0;
    }
    else
    {
        do
        {
            CAN1TBSEL = CAN1TFLG;
            send_buf  = CAN1TBSEL;
        } while (!send_buf);                                  //å¯»æ‰¾ç©ºé—²çš„ç¼“å†²å™¨                                                      //À©Õ¹Ö¡ID·¢ËÍ
        if (can_msg->IDE)
        {
            CAN1TXIDR0 =  (unsigned char)(can_msg->ID >> 21);
            CAN1TXIDR1 =  (unsigned char)(can_msg->ID >> 13) & 0xE0;
            CAN1TXIDR1 |= 0x18;
            CAN1TXIDR1 |= (unsigned char)(can_msg->ID >> 15) & 0x07;
            CAN1TXIDR2 =  (unsigned char)(can_msg->ID >> 7);
            CAN1TXIDR3 =  (unsigned char)(can_msg->ID << 1);
            CAN1TXIDR3_RTR = (unsigned char)can_msg->RTR;
        }
        else
        {                                                       //±ê×¼Ö¡ID·¢ËÍ
            CAN1TXIDR0 =  (unsigned char)(can_msg->ID >> 3);
            CAN1TXIDR1 =  (unsigned char)(can_msg->ID << 5);
            CAN1TXIDR1_SRR = (unsigned char)can_msg->RTR;
        }
        for (sp = 0 ;sp < can_msg->len ;sp++)                 //ä¾æ¬¡å°†æ•°æ®å†™å…¥å¯„å­˜å™¨
        {
            *((&CAN1TXDSR0) + sp) = (unsigned char)can_msg->data[sp];
        }
        CAN1TXDLR  = can_msg->len;                              //å†™å…¥æ•°æ®é•¿åº¦
        CAN1TXTBPR = can_msg->prty;                             //å†™å…¥ä¼˜å…ˆçº
        CAN1TFLG   = send_buf;                                  //æ¸…TXxæ ‡å¿—(ç¼“å†²å™¨å‡†å¤‡å‘é€)
        rebuf = 1;
    }
    return rebuf;
}

int CAN1_GetMsg(CAN_MsgType *can_msg)                       //CAN1æŽ¥æ”¶
{
    unsigned char sp = 0 ,rebuf = 1;                                //è®¾ç½®æŽ¥æ”¶æ•°æ®ä½æ•°

    if (!CAN1RFLG_RXF)                                    //æ£æµ‹æŽ¥æ”¶æ ‡å¿
    {
        rebuf = 0;
    }
    else
    {
        can_msg->IDE = CAN1RXIDR1_IDE;
        if (can_msg->IDE)                        //åˆ¤æ–­æ˜¯å¦ä¸ºæ ‡å‡†å¸§
        {
            can_msg->RTR = (CAN1RXIDR3 & 0x01);
            can_msg->ID = ((unsigned long)(CAN1RXIDR0 & 0xFF)) << 21;
            can_msg->ID = can_msg->ID | (((unsigned long)(CAN1RXIDR1 & 0xE0)) << 13);
            can_msg->ID = can_msg->ID | (((unsigned long)(CAN1RXIDR1 & 0x07)) << 15);
            can_msg->ID = can_msg->ID | (((unsigned long)(CAN1RXIDR2 & 0xFF)) << 7);
            can_msg->ID = can_msg->ID | (((unsigned long)(CAN1RXIDR3 & 0xFE)) >> 1);
        }
        else
        {
            can_msg->RTR = ((CAN1RXIDR1 >> 4) & 0x01);
            can_msg->ID  = (unsigned long)(CAN1RXIDR0 << 3) |   //è¯»å‡ºæŽ¥æ”¶å¸§IDå‰8ä½
                           (unsigned long)(CAN1RXIDR1 >> 5) ;   //å¹¶ä¸”ä¸Žä¸Šè¯»å‡ºæŽ¥æ”¶å¸§IDå3ä½
        }
        can_msg->len = CAN1RXDLR_DLC;                               //è¯»å‡ºæŽ¥æ”¶çš„æ•°æ®é•¿åº
        for (sp = 0 ;sp < can_msg->len ;sp++)                   //ä¾æ¬¡è¯»å‡ºæŽ¥æ”¶çš„æ¯ä¸ä½æ•°æ
        {
            can_msg->data[sp] = *((&CAN1RXDSR0) + sp);
        }
        CAN1RFLG = 0x01;                                          //æ¸…RXFæ ‡å¿—ä½(ç¼“å†²å™¨å‡†å¤‡æŽ¥æ”)
        rebuf = 1;
    }
    return rebuf;
}

/*int CAN1_GetChoiceMsg(CAN_MsgType *can_msg ,unsigned long id ,int ide)
{
    int rebuf = 0;
    if (CAN1_GetMsg(&can_msg) == 1)
    {
        if ((can_msg->ID == id) && (can_msg->IDE == ide))
        {
            rebuf = 1;
        }
    }
    return rebuf;
}*/

void CAN_Delay10ms(unsigned int i)                          //å»¶æ—¶
{
    unsigned int n ,m;

    for (n=0 ;n<250 ;n++)
    {
        for (m=0 ;m<(80*i) ;m++)
        {
        }
    }
}


