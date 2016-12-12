
#ifndef _LongPressButton_H_
#define _LongPressButton_H_

#include <Debouncer.h>

class LongPressButton
{
public:
	LongPressButton(uint8_t pin, uint16_t delay, uint16_t holdTime);

	void update();

	bool changed() { return hasChanged; }
	bool pressed() { return isPressed; }
	bool unpressed() { return !isPressed; }
	bool longPressed() { return isLongPressed; }
	bool longUnpressed() { return !isLongPressed; }

protected:
	Debouncer debouncer;

	uint8_t pin;
	uint16_t delay;
	uint16_t holdTime;

	bool hasChanged = false;
	bool isPressed = false;
	bool isLongPressed = false;
	unsigned long holdStart = 0;

};








#endif // _LongPressButton_H_
