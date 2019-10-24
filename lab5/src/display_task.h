/*
 * display_task.h
 *
 *  Created on: Oct 24, 2019
 *      Author: jacoboffersen
 */

#ifndef DISPLAY_TASK_H_
#define DISPLAY_TASK_H_

#include "display.h"
#include "sleep.h"
#include <pthread.h>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class DisplayTask {
public:
	DisplayTask();
	virtual ~DisplayTask();

	void task();



private:
	Display display_;
	std::queue<std::string> queue_;
	Sleep sleep;

	std::string line1_;
	std::string line2_;
};




#endif /* DISPLAY_TASK_H_ */
