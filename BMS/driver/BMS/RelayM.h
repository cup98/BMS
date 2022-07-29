#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"

/*typedef enum _RelayM_FnType
{
    RELAY_1;
    RELAY_2;
    RELAY_3;
    RELAY_4;
} RelayM_FnType;

typedef struct _RelayM_ControlType
{
    RELAY_1;
    RELAY_2;
    RELAY_3;
    RELAY_4;
} RelayM_ControlType;

typedef struct _RelayM_ActureType
{
    RELAY_1;
    RELAY_2;
    RELAY_3;
    RELAY_4;
} RelayM_ActureType;*/

typedef enum _RelayM_Object_Type        //构建继电器控制目标
{
    RELAYM_MASTER,
    RELAYM_PRECHANG,
} RelayM_Object_Type;

typedef struct _RelayM_CtrlType         //继电器目标状态
{
    int Master;                         //总正继电器
    int Precharge;                      //预充继电器
} RelayM_CtrlType;

typedef struct _RelayM_SwitchType       //开关目标状态
{
    int Master;                         //总正开关
    int Precharge;                      //预充开关
} RelayM_SwitchType;

extern void RelayM_Init(void);                                      //继电器模块由初始化函数
extern void RelayM_Control(RelayM_Object_Type object ,int state);   //控制继电器开关函数,控制继电器开关函数(控制目标,状态)
extern void RelayM_Change(RelayM_Object_Type object ,int state);    //切换开关函数,切换开关函数(控制目标,状态)

#endif

//----------------------------------------------------

typedef unsigned char      uint8;
typedef unsigned short int uint16;
typedef unsigned int       uint32;

#define RELAYM_MAX_NUM     8
#define RELAYM_RES_SUPPORT FALSE

/*写入继电器配置信息*/
uint8 RelayM_SetContorl(RelayM_ChannelType channel ,uint32 value)
{
    RelayM_Info[channel]->Control_data.ctrl_status = value;
    return 0;
}

uint32 RelayM_GetControl(RelayM_ChannelType channel)
{
    return RelayM_Acture[channel]->Control_status;
}

uint32 RelayM_GetActure(RelayM_ChannelType channel)
{
    return RelayM_Acture[channel]->acture_status;
}

uint32 RelayM_GetOnTime(RelayM_ChannelType channel)
{
    return RelayM_Acture[channel]->on_time;
}

uint8 RelayM_SetOnTime(RelayM_ChannelType channel ,uint32 value)
{
    RelayM_Info[channel]->Control_data.on_time = value;
}

uint32 RelayM_GetOffTime(RelayM_ChannelType channel)
{
    return RelayM_Acture[channel]->off_time;
}

uint8 RelayM_SetOffTime(RelayM_ChannelType channel ,uint32 value)
{
    RelayM_Info[channel]->Control_data.off_time = value;
}

uint32 RelayM_GetRes(RelayM_ChannelType channel)
{
    return RelayM_Acture[channel]->res_value;
}

uint8 RelayM_SetRes(RelayM_ChannelType channel ,uint32 value)
{
    RelayM_Info[channel]->Control_data.res_value = value;
}

uint8 RelayM_Fault(RelayM_ChannelType channel)
{
    if ()
}

typedef enum _RelayM_FaultStatusType
{
    RELAYM_NORMAL,
    RELAYM_ADHESION,
    RELAYM_OPEN_LOOP,
} RelayM_FaultStatusType;

typedef enum _RelayM_AttributeType
{
    RelayM_ACTURE_CONTROL,
    RelayM_ACTURE_STATUS,
    RelayM_ACTURE_ON_TIME,
    RelayM_ACTURE_OFF_TIME,
    RelayM_ACTURE_RES_VALUE,
    RelayM_CTRL_STATUS,
    RelayM_CTRL_ON_TIME,
    RelayM_CTRL_OFF_TIME,
    RelayM_CTRL_RES_VALUE,
} RelayM_AttributeType;

typedef enum _RelayM_ChannelType
{
    RelayM_Channel_0,
    RelayM_Channel_1,
    RelayM_Channel_2,
    RelayM_Channel_3,
    RelayM_Channel_4,
    RelayM_Channel_5,
    RelayM_Channel_6,
    RelayM_Channel_7,
} RelayM_ChannelType;

typedef struct _RelayM_ActureType
{
    uint32 *Control_status;
    uint32 *acture_status;
    uint32 *on_time;
    uint32 *off_time;
    uint32 *res_value;
} RelayM_ActureType;

RelayM_ActureType RelayM_Acture[RELAYM_MAX_NUM] =
{
    {
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[0].on_time,
        &RelayM_CtrlType[0].off_time,
        &RelayM_CtrlType[0].res_value
    },
    {
        &RelayM_CtrlType[1].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[1].on_time,
        &RelayM_CtrlType[1].off_time,
        &RelayM_CtrlType[1].res_value
    },
    {
        &RelayM_CtrlType[2].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[2].on_time,
        &RelayM_CtrlType[2].off_time,
        &RelayM_CtrlType[2].res_value
    },
    {
        &RelayM_CtrlType[3].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[3].on_time,
        &RelayM_CtrlType[3].off_time,
        &RelayM_CtrlType[3].res_value
    },
    {
        &RelayM_CtrlType[4].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[4].on_time,
        &RelayM_CtrlType[4].off_time,
        &RelayM_CtrlType[4].res_value
    },
    {
        &RelayM_CtrlType[5].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[5].on_time,
        &RelayM_CtrlType[5].off_time,
        &RelayM_CtrlType[5].res_value
    },
    {
        &RelayM_CtrlType[6].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[6].on_time,
        &RelayM_CtrlType[6].off_time,
        &RelayM_CtrlType[6].res_value
    },
    {
        &RelayM_CtrlType[7].ctrl_status,
        &RelayM_CtrlType[0].ctrl_status,
        &RelayM_CtrlType[7].on_time,
        &RelayM_CtrlType[7].off_time,
        &RelayM_CtrlType[7].res_value
    }
};

/*控制状态，需要设置的状态*/
typedef struct _RelayM_ControlType
{
    uint32 ctrl_status;/*继电器控制状态*/
    uint32 on_time;/*继电器控制闭合时间*/
    uint32 off_time;/*继电器控制断开时间*/
    uint32 res_value;/*继电器内阻设置*/
} RelayM_CtrlType;

RelayM_CtrlType RelayM_CtrlType[RELAYM_MAX_NUM] =
{
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
};

RelayM_CtrlType RelayM_CtrlType[RELAYM_MAX_NUM] =
{
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
};

typedef struct _RelayM_InfoType
{
    uint8 channel;
    RelayM_CtrlType *Control_data[];
    RelayM_FaultStatusType fault;
} RelayM_InfoType;

RelayM_InfoType RelayM_Info[] =
{
    {0 ,&RelayM_CtrlType[0] ,RELAYM_NORMAL};
    {1 ,&RelayM_CtrlType[1] ,RELAYM_NORMAL};
    {2 ,&RelayM_CtrlType[2] ,RELAYM_NORMAL};
    {3 ,&RelayM_CtrlType[3] ,RELAYM_NORMAL};
    {4 ,&RelayM_CtrlType[4] ,RELAYM_NORMAL};
    {5 ,&RelayM_CtrlType[5] ,RELAYM_NORMAL};
    {6 ,&RelayM_CtrlType[6] ,RELAYM_NORMAL};
    {7 ,&RelayM_CtrlType[7] ,RELAYM_NORMAL};
};

void RelayM_InterruptON()
{
}

void RelayM_InterruptOFF()
{
}

void RelayM_Control(uint8 channel ,RelayM_AttributeType attribute ,uint32 value)
{
    switch (attribute)
    {
        case RelayM_CTRL_STATUS:
        {
            RelayM_SetContorl(channel ,value);
        } break;

        case RelayM_CTRL_ON_TIME:
        {
            RelayM_SetOnTime(channel ,value);
        } break;

        case RelayM_CTRL_OFF_TIME:
        {
            RelayM_SetOffTime(channel ,value);
        } break;

        case RelayM_CTRL_RES_VALUE:
        {
            RelayM_SetRes(channel ,value);
        } break;
    }
}

uint32 RelayM_Acture(uint8 channel ,RelayM_AttributeType attribute)
{
    uint32 rebuf;
    switch (attribute)
    {
        case RelayM_ACTURE_CONTROL:
        {
            rebuf = RelayM_GetControl(channel);
        } break;

        case RelayM_ACTURE_STATUS:
        {
            rebuf = RelayM_GetActure(channel);
        } break;

        case RelayM_ACTURE_ON_TIME:
        {
            rebuf = RelayM_GetOnTime(channel);
        } break;

        case RelayM_ACTURE_OFF_TIME:
        {
            rebuf = RelayM_GetOffTime(channel);
        } break;

        case RelayM_ACTURE_RES_VALUE:
        {
            rebuf = RelayM_GetRes(channel);
        } break;
    }
}















//Std_RetureType RelayM_Control(RelayM_Fn_Type fn, RelayM_ControlType ctl)

/*
void RelayM_GetStatus(RelayM_ActureType *state,)
{

}  */




#define RELAYM_RES_SUPPORT FALSE
#define RELAYM_SET_SUPPORT TRUE

/*Ð´Èë¼ÌµçÆ÷ÅäÖÃÐÅÏ¢*/
uint8 RelayM_SetControL(uint8 ctl ,uint8 pas)
{
      return ctl - pas;
}
/*Ð´Èë¼ÌµçÆ÷ÅäÖÃÐÅÏ¢*/
uint8 RelayM_GetControL(uint8 pas)
{

}

uint8 RelayM_SetOnTime(uint8 ctl ,uint8 pas)
{

}
uint8 RelayM_GetOnTime(uint8 pas)
{
    return  pas;
}

/*Êµ¼Ê×´Ì¬ÐÅÏ¢£¬ÐèÒª¶ÁÈ¡µÄ×´Ì¬*/
typedef struct _RelayM_ActureType
{
    uint8 (*Act)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄÊµ¼Ê×´Ì¬*/
    uint8 (*Ctl)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 (*OnTime)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 (*OffTime)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 (*Res)(uint8 pas);/*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8    passage;
}RelayM_ActureType;

/*¿ØÖÆ×´Ì¬£¬ÐèÒªÉèÖÃµÄ×´Ì¬*/
typedef struct _RelayM_CtlType
{
    uint8 (*Ctl)(uint8 ctl ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ×´Ì¬*/
    uint8 (*OnTime)(uint8 time ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ±ÕºÏÊ±¼ä*/
    uint8 (*OffTime)(uint8 time ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ¶Ï¿ªÊ±¼ä*/
    uint8 (*Res)(uint8 res,uint8 pas);/*¼ÌµçÆ÷ÄÚ×èÉèÖÃ*/
    uint8    passage;
}RelayM_CtlType;


typedef struct _RelayM_MsgCfgType
{
    uint8    passage;
    RelayM_ActureType *get;
    RelayM_CtlType *ctl;
}RelayM_MsgCfgType;

typedef struct _RelayM_CtlCfgType
{
    uint8    passage;
    RelayM_CtlType *ctl;
}RelayM_CtlCfgType;


typedef struct _RelayM_ActCfgType
{
    uint8    passage;
    RelayM_ActureType *get;
}RelayM_ActCfgType;


RelayM_ActureType  ActureData[] =
{
    {RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime},

};
RelayM_CtlType   ControlData[]=
{
    {RelayM_SetOnTime,RelayM_SetOnTime,RelayM_SetOnTime,RelayM_SetOnTime},
};


RelayM_MsgCfgType StateData[]  =
{
   {0,&ActureData[0],&ControlData[0]},
   {0,&ActureData[1],&ControlData[1]},
};


typedef struct _RelayM_ActureCallType
{
    uint8 Act;/*¼ÌµçÆ÷Êä³öµÄÊµ¼Ê×´Ì¬*/
    uint8 Ctl;/*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 OnTime;/*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 OffTime;/*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 Res;/*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8 passage;
}RelayM_ActureCallType;

RelayM_InterruptOFF()
{

}

RelayM_InterruptON()
{

}
RelayM_ActureCallType RelayM_ReadAllData(uint8 pra)
{
    uint8 i;
    RelayM_ActureCallType retval;
    /**/
    RelayM_InterruptOFF();
    retval.Act = StateData[pra].get -> Act(pra);
    retval.Ctl = StateData[pra].get -> Ctl(pra);
    retval.OnTime = StateData[pra].get -> OnTime(pra);
    retval.OffTime = StateData[pra].get -> OffTime(pra);
    retval.Res = StateData[pra].get -> Res(pra);
    retval.passage = StateData[pra].get->passage;
    RelayM_InterruptON();
    return retval;
}


typedef enum _Hv_ChannelType
{
    RELAYM_ACTSTATE,
    RELAYM_CONTROLSTATE,
    RELAYM_ONTIMEACTSTATE,
    RELAYM_OFFTIMESTATE,
    RELAYM_RESSTATE,
} RELAYM_STATEMSGTYPE;
RelayM_ReadAloneData(1,RELAYM_ACTSTATE)
uint8 RelayM_ReadAloneData(uint8 pra ,RELAYM_STATEMSGTYPE state)
{
    uint8 retval;
    /**/
    RelayM_InterruptOFF();
    switch ( state )
    {
        case RELAYM_ACTSTATE:
        retval = StateData[pra].get -> Act(pra);
        break;

        case RELAYM_CONTROLSTATE:
        retval = StateData[pra].get -> Ctl(pra);
        break;

        case RELAYM_ONTIMEACTSTATE:
        retval = StateData[pra].get -> OnTime(pra);
        break;

        case RELAYM_OFFTIMESTATE:
        retval = StateData[pra].get -> OffTime(pra);
        break;

        case RELAYM_RESSTATE:
         retval = StateData[pra].get -> Res(pra);
        break;
    }
    RelayM_InterruptON();

    return retval;
}



//Std_RetureType RelayM_Control(RelayM_Fn_Type fn, RelayM_ControlType ctl)

/*
void RelayM_GetStatus(RelayM_ActureType *state,)
{

}  */

void main(void) {
  /* put your own code here */


    EnableInterrupts;
  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
