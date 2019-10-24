/*
 * keypad_task.h
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#ifndef KEYPAD_TASK_H_
#define KEYPAD_TASK_H_

#include "keypad.h"
#include <queue>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//#define MESSAGE_QUEUE  "/keypad_queue"
//#define MAX_SIZE    	1024
//#define PMODE 			0655
//mqd_t message_queue;



class KeypadTask {
public:
	KeypadTask();
	virtual ~KeypadTask();

	static void* task();
	pthread_t init();


private:
	Keypad keypad_;
	std::queue<std::string> queue_;

	pthread_t thread_;
};



#endif /* KEYPAD_TASK_H_ */
