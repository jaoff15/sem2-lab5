/*
 *
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#include "numpad_driver_task.h"

NumpadDriverTask::NumpadDriverTask() {
	numpad_driver_.init();
	std::cout << "Numpad Driver Task Initialized" << std::endl;
}

NumpadDriverTask::~NumpadDriverTask() {

}
void NumpadDriverTask::setMessageQueue(std::string queue_name) {
	message_queue_descriptor_ = queue_name;
}


void NumpadDriverTask::taskHandler(){
	mqd_t mq = mq_open(message_queue_descriptor_.c_str(), O_WRONLY);
	int i = 0;
	std::string key;
	while(1){
//		std::string key = numpad_driver_.check();
		if(key!= ""){
	//		std::cout << key << std::endl;
			std::cout << "numpad send" << std::endl;
			mq_send(mq, key.c_str(), key.length(), 0);
		}

		key = std::to_string(i);
		i++;
		sleep_.millisecond(1000);
	}
}
