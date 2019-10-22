/*
 * keypad_task.h
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#ifndef KEYPAD_TASK_H_
#define KEYPAD_TASK_H_

#include "keypad.h"
#include <mqueue.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MESSAGE_QUEUE  "/keypad_queue"
#define MAX_SIZE    	1024
#define PMODE 			0655
//mqd_t message_queue;


void* keypadTask(void *ptr) ;
void* consumer(void *ptr) ;
void* producer(void *ptr);

class KeypadTask {
public:
	KeypadTask();
	virtual ~KeypadTask();

	void* task(void *ptr);
	std::string check();

private:
	Keypad keypad_;
	mqd_t queue_;
};

#endif /* KEYPAD_TASK_H_ */
