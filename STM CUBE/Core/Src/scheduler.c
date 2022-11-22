/*
 * scheduler.c
 *
 *  Created on: Nov 22, 2022
 *      Author: Welcome
 */
#include "scheduler.h"

unsigned char current_index_task = 0;

unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX){
	unsigned char Return_code ;
	SCH_tasks_G [TASK_INDEX].pTask = 0x0000 ;
	SCH_tasks_G [TASK_INDEX].Delay = 0;
	SCH_tasks_G [TASK_INDEX].Period = 0;
	SCH_tasks_G [TASK_INDEX].RunMe = 0;
	current_index_task--;
	return Return_code ; // return status
}
void SCH_Init(void){
	unsigned char i ;
	for(i = 0; i < current_index_task; i++){
		SCH_Delete_Task(i);
	}
}
void SCH_Add_Task( void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period = PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void){
	for(int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay --;
		}else{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(i == 4){// one-shot task
			if(SCH_tasks_G[i].RunMe > 0){
				SCH_tasks_G[i].RunMe--;
				(*SCH_tasks_G[i].pTask)();
				SCH_Delete_Task(i);
			}
			//delete task out of SCH_tasks_G
		}
		else{
			if(SCH_tasks_G[i].RunMe > 0){
				SCH_tasks_G[i].RunMe--;
				(*SCH_tasks_G[i].pTask)();
			}
		}
	}
}
