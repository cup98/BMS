#include <hidef.h>
#include "derivative.h"
#include "CAN.h"
#include "ECT.h"
#include "PIT.h"
#include "PLL.h"
#include "Node.h"
#include "Hv.h"
#include "Node.h"
#include "PrechargeM.h"
#include "RelayM.h"

#define PIN_PC4       PORTC_PC4
#define PIN_PC4_DDRC  DDRC_DDRC4
#define PIN_PC5       PORTC_PC5
#define PIN_PC5_DDRC  DDRC_DDRC5

void main(void)
{
    DisableInterrupts;
    PIN_PC4 = 1;
    PIN_PC4_DDRC = 1;
    PIN_PC5 = 0;
    PIN_PC5_DDRC = 1;

    PLL_Init();
    ECT_Init();
    CAN_Init();
    PIT_Init();
    Hv_Init();
    Node_Init();
    PrechargeM_Init();
    RelayM_Init();
    EnableInterrupts;

    for(;;)
    {
        _FEED_COP();
    }
}
