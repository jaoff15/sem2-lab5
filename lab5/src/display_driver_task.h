/*
 *
 *
 *  Created on: Oct 24, 2019
 *      Author: jacoboffersen
 */

#ifndef DISPLAY_DRIVER_TASK_H_
#define DISPLAY_DRIVER_TASK_H_

#include "sleep.h"
#include "display_driver.h"
#include "common.h"

#include <pthread.h>
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



class DisplayDriverTask {
public:
	DisplayDriverTask();
	virtual ~DisplayDriverTask();

	void setMessageQueue(std::string queue_name);
	void taskHandler();
private:
	DisplayDriver display_driver_;
	std::string message_queue_descriptor_;
	Sleep sleep_;
};




#endif /* DISPLAY_DRIVER_TASK_H_ */
