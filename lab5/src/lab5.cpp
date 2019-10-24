//============================================================================
// Name        : lab3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>



#include "display_task.h"
#include "keypad_task.h"
#include "sleep.h"

void* kTask(void *ptr){

}

void* dTask(void *ptr){

}
int main() {


	Sleep sleep;


	std::cout << "Started" << std::endl;

	KeypadTask keypadTask;
	pthread_t thread1 = keypadTask.init();
//	DisplayTask display;


//	pthread_t thread1, thread2;
	int iret1, iret2;

	/* Create independent threads each of which will execute function */
	iret1 = pthread_create(&thread1, NULL, kTask, NULL);
//	iret1 = pthread_create(&thread2, NULL, dTask, NULL);

	/* Wait till threads are complete before main continues. Unless we  */
	/* wait we run the risk of executing an exit which will terminate   */
	/* the process and all threads before the threads have completed.   */
	pthread_join(thread1, NULL);
//	pthread_join(thread2, NULL);

	printf("Thread 1 returns: %d\n", iret1);
	printf("Thread 2 returns: %d\n", iret2);

//	while (1) {
//
//		std::string key = keypad.check();
//		if (key != "") {
//			std::cout << key << std::endl;
//
//
//		}
//	}
	return 0;
}
