#ifndef __NODE_CFG_H
#define __NODE_CFG_H

#include "hidef.h"
#include "derivative.h"
#include "Node.h"

typedef struct _Node_StateCfgType
{
  unsigned char num;
  Node_StateType *state;
} Node_StateCfgType;

typedef struct _Node_StateInfoType
{
  unsigned char node;
  Node_StateCfgType *state;
} Node_StateInfoType; 

extern Node_StateType node_pre_state_start[];
extern Node_StateType node_pre_state_finish[];
extern Node_StateType node_pre_state_fault[];
extern Node_StateCfgType node_state_cfg[];
extern Node_StateInfoType node_state_info;

#endif