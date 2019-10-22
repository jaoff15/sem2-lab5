//============================================================================
// Name        : lab3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>

#include "display.h"
#include "keypad_task.h"

int main() {
//	std::string str1 = "Line 1";
//	std::string str2 = "Line 2";
//	Display display;
//	display.init();
//	display.print(str1, str2);

//	Keypad keypad;
//	keypad.init();

//	Sleep sleep;

	std::cout << "Started" << std::endl;

//	KeypadTask keypadTask;

	pthread_t thread1, thread2;
	int iret1, iret2;
	/* Create independent threads each of which will execute function */
//	iret1 = pthread_create(&thread1, NULL, keypadTask, NULL);
	iret1 = pthread_create(&thread1, NULL, producer, NULL);
	iret2 = pthread_create(&thread2, NULL, consumer, NULL);

	/* Wait till threads are complete before main continues. Unless we  */
	/* wait we run the risk of executing an exit which will terminate   */
	/* the process and all threads before the threads have completed.   */
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Thread 1 returns: %d\n", iret1);
	printf("Thread 2 returns: %d\n", iret2);

//	while (1) {
//
//		std::string key = keypad.check();
//		if (key != "") {
//			std::cout << key << std::endl;
//
//			if (key == "1D") {
//				str1 = "";
//				sleep.millisecond(500);
//			} else {
//				if (str1.length() >= 16) {	// Remove first element if string becomes too long
//					str1 = str1.substr(1);
//				}
//				str1 += key;
//			}
//			display.print(str1, key);
//		}
//	}
	return 0;
}
