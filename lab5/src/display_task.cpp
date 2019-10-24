/*
 * display_task.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: jacoboffersen
 */

#include "display_task.h"

DisplayTask::DisplayTask() {
	line1_ = "Line 1";
	line2_ = "Line 2";
	display_.init();
	display_.print(line1_, line2_);

}

DisplayTask::~DisplayTask() {

}


void DisplayTask::task(){
	if(!queue_.empty()){
		std::string key = queue_.front();
		queue_.pop();
		if (key == "1D") {
			line1_ = "";
			sleep.millisecond(500);
		} else {
			if (line1_.length() >= 16) {	// Remove first element if string becomes too long
				line1_ = line1_.substr(1);
			}
			line1_ += key;
		}
		line2_ = key;
		display_.print(line1_, line2_);
	}
}

