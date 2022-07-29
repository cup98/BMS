#ifndef __NODE_CFG_H
#define __NODE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"

extern const Node_StateType Node_Fault_State[];
extern const Node_StateType Node_PreFinish_State[];
extern const Node_StateType Node_Charge_State[];
extern const Node_StateCfgType Node_StateCfg[];
extern Node_ElementBackType Node_ElementBack;

#endif