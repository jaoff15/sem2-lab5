/*
 *
 *
 *  Created on: Oct 24, 2019
 *      Author: jacoboffersen
 */

#include "display_driver_task.h"

DisplayDriverTask::DisplayDriverTask() {
	display_driver_.init();
	std::cout << "Display Driver Task Initialized" << std::endl;
}

DisplayDriverTask::~DisplayDriverTask() {

}



void DisplayDriverTask::setMessageQueue(std::string queue_name) {
	message_queue_descriptor_ = queue_name;
}

void DisplayDriverTask::taskHandler(){
	mqd_t mq = mq_open(message_queue_descriptor_.c_str(), O_RDONLY);
	char buffer[MAX_SIZE + 1];
	while(1){
		mq_receive(mq, buffer, MAX_SIZE, NULL);
		if(buffer[0] != 0){
			std::cout << "display received" << std::endl;
			std::cout << buffer << std::endl;
		}

		sleep_.millisecond(100);
		std::cout << "display_running" << std::endl;
	}
}
