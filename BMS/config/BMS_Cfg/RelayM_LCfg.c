#include "RelayM_LCfg.h"

RelayM_ControlType RelayM_CtrlData[RELAYM_MAX_NUM] =    //继电器控制数据存放
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

RelayM_ActureType RelayM_ActureData[RELAYM_MAX_NUM] =   //继电器当前状态存放
{
    {
        &(RelayM_CtrlData[0].ctrl_status),              //演示时指向继电器控制数据结构体
        &(RelayM_CtrlData[0].on_time),
        &(RelayM_CtrlData[0].off_time),
        &(RelayM_CtrlData[0].res_value)
    },
    {
        &(RelayM_CtrlData[1].ctrl_status),
        &(RelayM_CtrlData[1].on_time),
        &(RelayM_CtrlData[1].off_time),
        &(RelayM_CtrlData[1].res_value)
    },
    {
        &(RelayM_CtrlData[2].ctrl_status),
        &(RelayM_CtrlData[2].on_time),
        &(RelayM_CtrlData[2].off_time),
        &(RelayM_CtrlData[2].res_value)
    },
    {
        &(RelayM_CtrlData[3].ctrl_status),
        &(RelayM_CtrlData[3].on_time),
        &(RelayM_CtrlData[3].off_time),
        &(RelayM_CtrlData[3].res_value)
    },
    {
        &(RelayM_CtrlData[4].ctrl_status),
        &(RelayM_CtrlData[4].on_time),
        &(RelayM_CtrlData[4].off_time),
        &(RelayM_CtrlData[4].res_value)
    },
    {
        &(RelayM_CtrlData[5].ctrl_status),
        &(RelayM_CtrlData[5].on_time),
        &(RelayM_CtrlData[5].off_time),
        &(RelayM_CtrlData[5].res_value)
    },
    {
        &(RelayM_CtrlData[6].ctrl_status),
        &(RelayM_CtrlData[6].on_time),
        &(RelayM_CtrlData[6].off_time),
        &(RelayM_CtrlData[6].res_value)
    },
    {
        &(RelayM_CtrlData[7].ctrl_status),
        &(RelayM_CtrlData[7].on_time),
        &(RelayM_CtrlData[7].off_time),
        &(RelayM_CtrlData[7].res_value)
    }
};


