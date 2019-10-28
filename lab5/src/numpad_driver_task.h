/*
 *
 *
 *  Created on: Oct 22, 2019
 *      Author: jacoboffersen
 */

#ifndef NUMPAD_DRIVER_TASK_H_
#define NUMPAD_DRIVER_TASK_H_

#include <mqueue.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "common.h"
#include "numpad_driver.h"
#include "sleep.h"

class NumpadDriverTask {
public:
	NumpadDriverTask();
	virtual ~NumpadDriverTask();

	void setMessageQueue(std::string queue_name);
	void taskHandler();
private:
	std::string message_queue_descriptor_;
	NumpadDriver numpad_driver_;
	Sleep sleep_;
};




#endif /* NUMPAD_DRIVER_TASK_H_ */
