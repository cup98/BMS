#include "Node.h"
#include "Pre_Cfg.h"
#include "PrechargeM.h"
#include "CAN_Cfg.h"

int Init_Node = 0;									//设置节点标志位初始为1

 PreNode_Struct_Type Node_StateTransition_Table[3][4] =
 {
 	{
 		{0 ,Pre_Cfg_Fault ,2 ,1 ,No_Act ,0 },
 		{0 ,Pre_Cfg_Fault ,2 ,0 ,PrechargeM_StartPre ,1 },
 	},

 	{
 		{1 ,Pre_Cfg_Fault ,4 ,1 ,PrechargeM_StopPre ,0 },
 		{1 ,PrechargeM_IsFail ,4 ,1 ,PrechargeM_StopPre ,0 },
 		{1 ,PrechargeM_IsFinish ,4 ,1 ,PrechargeM_Change ,2 },
 		{1 ,PrechargeM_IsFinish ,4 ,0 ,No_Act ,1 },
 	},

 	{
 		{2 ,Pre_Cfg_Fault ,2 ,1 ,PrechargeM_StopMaster ,0 },
 		{2 ,Pre_Cfg_Fault ,2 ,0 ,No_Act ,2 },
 	}
 };

void Node_Init(void)								//Node模块初始化
{

}

void No_Act(void)									//Node模块执行空函数
{

}

void Node_Poll(void)
{
	int i = 0;
	int Run_Num = Node_StateTransition_Table[Init_Node][0].Branch_Num;
  CAN_PreStateOut_TestType.Data[6] = Run_Num;
	CAN1_SendMsg(&CAN_PreStateOut_TestType);
	for (i = 0; i < Run_Num; i++)
	{
		if (Node_StateTransition_Table[Init_Node][i].Condition() ==
			Node_StateTransition_Table[Init_Node][i].Branch_Condition)
		{
		  	CAN_PreStateOut_TestType.Data[0] = Init_Node;

			Node_StateTransition_Table[Init_Node][i].Action();
			Init_Node = Node_StateTransition_Table[Init_Node][i].Next_Node_Num;

		  	CAN_PreStateOut_TestType.Data[1] = Init_Node;
	    	CAN1_SendMsg(&CAN_PreStateOut_TestType);
			break;
		}
	}
}



/*typedef int state;
typedef int event_id;
typedef int (*action)(event_id *);

typedef struct
{
	state current_state;
	event_id event;
	state next_state;
	action act;
} state_machine_form;


state_machine_form password_states[] =
{
	{STATE_NONE, EVENT_INPUT_9, STATE_9, NULL},
	{STATE_9, 	 EVENT_INPUT_5, STATE_5, NULL},
	{STATE_5, 	 EVENT_INPUT_2, STATE_2, NULL},
	{STATE_2, 	 VENT_INPUT_7, 	STATE_7, unlock},
};
#define PASSWORD_STATES_COUNT sizeof(password_states)/sizeof(password_states[0])


static state_machine_form *find_trans(state_machine *sm, event_id *event)
{
	int index;
	for (index = 0; index < sm->trans_num; index++)
	{
    	if ((sm->transform[index].current_state == sm->current_state) &&
    		(sm->transform[index].event == *event))
    	{
      		return &sm->transform[index];
    	}
  	}
  	return NULL;
}

int run_machine(state_machine *sm, event_id *event)
{
	state_machine_form *trans = find_trans(sm, event);
 	if (trans == NULL)
 	{
  		return -1;
 	}
 	sm->current_state = trans->next_state;
 	action act = trans->act;
 	if (act)
 	{
  		act(event);
 	}
	return 0;
}*/





















