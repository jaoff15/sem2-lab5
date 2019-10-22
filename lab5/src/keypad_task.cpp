/*
 * keypad_task.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#include "keypad_task.h"

KeypadTask::KeypadTask() {
	/* Init keypad */
//	keypad_.init();

	/* Init message queue */
	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 3;
	queue_ = mq_open(MESSAGE_QUEUE, O_CREAT, PMODE, &attr);
}

KeypadTask::~KeypadTask() {

}

std::string KeypadTask::check(){
	return keypad_.check();
}

void* KeypadTask::task(void *ptr){
	while(1){
		std::string key = keypad_.check();
	}
}

void* keypadTask(void *ptr) {
//	mqd_t mq = mq_open(MESSAGE_QUEUE, O_WRONLY);
//	KeypadTask task;
	std::cout << "Producer started" << std::endl;
	int i;
	mqd_t mq = mq_open(MESSAGE_QUEUE, O_WRONLY);
	int counter;
	for (i = 0; i < 500; i++) {
		counter++;
		std::string s = std::to_string(counter);
		mq_send(mq, s.c_str(), 3, 0);
	}
//	while(1){
//		std::string key = task.check();
//		if (key != "") {
//			std::cout << 'p' << key << std::endl;
//			mq_send(mq, key.c_str(), 3, 0);
//		}
//
//	}
}

void* producer(void *ptr) {
	int i;
	mqd_t mq = mq_open(MESSAGE_QUEUE, O_WRONLY);
	int counter;
	for (i = 0; i < 500; i++) {
		counter++;
		std::string s = std::to_string(counter);
		mq_send(mq, s.c_str(), 3, 0);
	}
}

void* consumer(void *ptr) {
//	mqd_t mq = mq_open(MESSAGE_QUEUE, O_RDONLY);
//	char buffer[MAX_SIZE + 1];
	std::cout << "Consumer started" << std::endl;
	mqd_t mq = mq_open(MESSAGE_QUEUE, O_RDONLY);
	char buffer[MAX_SIZE + 1];
	int i;
	for (i = 0; i < 500; i++) {
		mq_receive(mq, buffer, MAX_SIZE, NULL);
		printf("%s, ", buffer);
	}
//	while(1){
//		mq_receive(mq, buffer, MAX_SIZE, NULL);
//		if(buffer != NULL){
//			printf("c%s, ", buffer);
//		}
//
//	}

}

