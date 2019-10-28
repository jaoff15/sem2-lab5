//============================================================================
// Name        : lab5.cpp
// Author      : Jacob Offersen
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <mqueue.h>
#include <pthread.h>
#include "common.h"


mqd_t message_queue;

#include "display_driver_task.h"
#include "numpad_driver_task.h"
#include "sleep.h"

NumpadDriverTask numpad_driver_task;
DisplayDriverTask display_driver_task;

void *task1( void *ptr );
void *task2( void *ptr );
void *task1(void *ptr ){
	numpad_driver_task.taskHandler();
}
void *task2(void *ptr ){
	display_driver_task.taskHandler();
}

int main(){
	std::cout << "Started" << std::endl;
	pthread_t thread1, thread2;
	int  iret1, iret2;

	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 1;
	message_queue = mq_open(MESSAGE_QUEUE, O_CREAT, PMODE, &attr);


	numpad_driver_task.setMessageQueue(MESSAGE_QUEUE);
	display_driver_task.setMessageQueue(MESSAGE_QUEUE);

	iret2 = pthread_create( &thread1, NULL, task2, NULL);
	iret1 = pthread_create( &thread1, NULL, task1, NULL);


	/* Wait till threads are complete before main continues. Unless we  */
	/* wait we run the risk of executing an exit which will terminate   */
	/* the process and all threads before the threads have completed.   */

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	//
	printf("Thread 1 returns: %d\n",iret1);
	printf("Thread 2 returns: %d\n",iret2);
	exit(0);
}

