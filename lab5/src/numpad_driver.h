/*
 *
 *  Created on: Sep 24, 2019
 *      Author: jacoboffersen
 */

#ifndef NUMPAD_DRIVER_H_
#define NUMPAD_DRIVER_H_

#include "types.hpp"
#include <string>
#include <iostream>

#include "gpio.h"

#define NUMPAD_PIN_COL_BASE 992
#define NUMPAD_PIN_COL_LEN 4
#define NUMPAD_PIN_ROW_BASE 996
#define NUMPAD_PIN_ROW_LEN 4

const std::string keys_[4][4] = { { "1", "2", "3", "A" },
								  { "4", "5", "6", "B" },
								  { "7", "8", "9", "C" },
								  { "0", "F", "E", "D" } };

class NumpadDriver {
public:
	NumpadDriver();
	virtual ~NumpadDriver();

	void init();
	std::string check();

private:
	bool initialized_;

	u8 width_;
	u8 height_;

	Gpio column_[4];
	Gpio row_[4];

	std::string last_keys_pressed;

	bool getValue(const u8 col, const u8 row);
};

#endif /* NUMPAD_DRIVER_H_ */
