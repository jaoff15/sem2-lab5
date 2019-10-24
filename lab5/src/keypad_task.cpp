/*
 * keypad_task.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#include "keypad_task.h"

KeypadTask::KeypadTask() {
	/* Init keypad */
	keypad_.init();

	/* Init message queue */

	/* Start task */
	thread_ = NULL;
}

KeypadTask::~KeypadTask() {

}

pthread_t KeypadTask::init(){
	int iret1;
	pthread_t thread_;
	pthread_create(&thread_, NULL, task, NULL);
	return thread_;
}

static void* KeypadTask::task(){
	std::string key = keypad_.check();
	if (key != "") {
		queue_.push(key);
	}
}


