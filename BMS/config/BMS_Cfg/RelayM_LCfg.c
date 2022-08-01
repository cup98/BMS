#include "RelayM_LCfg.h"

RelayM_ControlType RelayM_OriginDataDemo[RELAYM_MAX_NUM] =    //继电器控制数据存放
{
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0}
};

RelayM_ControlType RelayM_CtrlData[RELAYM_MAX_NUM] =    //继电器控制数据存放
{
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0}
};

/*RelayM_ActureType RelayM_ActureData[RELAYM_MAX_NUM] =   //继电器当前状态存放
{
    {
        &(RelayM_OriginDataDemo[0].ctrl_status),              //演示时指向继电器控制数据结构体
        &(RelayM_OriginDataDemo[0].on_time),
        &(RelayM_OriginDataDemo[0].off_time),
        &(RelayM_OriginDataDemo[0].res_value)
    },
    {
        &(RelayM_OriginDataDemo[1].ctrl_status),
        &(RelayM_OriginDataDemo[1].on_time),
        &(RelayM_OriginDataDemo[1].off_time),
        &(RelayM_OriginDataDemo[1].res_value)
    },
    {
        &(RelayM_OriginDataDemo[2].ctrl_status),
        &(RelayM_OriginDataDemo[2].on_time),
        &(RelayM_OriginDataDemo[2].off_time),
        &(RelayM_OriginDataDemo[2].res_value)
    },
    {
        &(RelayM_OriginDataDemo[3].ctrl_status),
        &(RelayM_OriginDataDemo[3].on_time),
        &(RelayM_OriginDataDemo[3].off_time),
        &(RelayM_OriginDataDemo[3].res_value)
    },
    {
        &(RelayM_OriginDataDemo[4].ctrl_status),
        &(RelayM_OriginDataDemo[4].on_time),
        &(RelayM_OriginDataDemo[4].off_time),
        &(RelayM_OriginDataDemo[4].res_value)
    },
    {
        &(RelayM_OriginDataDemo[5].ctrl_status),
        &(RelayM_OriginDataDemo[5].on_time),
        &(RelayM_OriginDataDemo[5].off_time),
        &(RelayM_OriginDataDemo[5].res_value)
    },
    {
        &(RelayM_OriginDataDemo[6].ctrl_status),
        &(RelayM_OriginDataDemo[6].on_time),
        &(RelayM_OriginDataDemo[6].off_time),
        &(RelayM_OriginDataDemo[6].res_value)
    },
    {
        &(RelayM_OriginDataDemo[7].ctrl_status),
        &(RelayM_OriginDataDemo[7].on_time),
        &(RelayM_OriginDataDemo[7].off_time),
        &(RelayM_OriginDataDemo[7].res_value)
    }
};*/


