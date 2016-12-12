
#ifndef _Button_H_
#define _Button_H_

#include <Debouncer.h>

class Button
{
public:
	Button(int pin, int delay, int holdTime);

	void update();

	bool changed() { return hasChanged; }
	bool pressed() { return isPressed; }
	bool unpressed() { return !isPressed; }
	bool longPressed() { return isLongPressed; }
	bool longUnpressed() { return !isLongPressed; }

protected:
	Debouncer debouncer;

	int pin;
	int delay;
	int holdTime;

	bool hasChanged = false;
	bool isPressed = false;
	bool isLongPressed = false;
	unsigned long holdStart = 0;

};








#endif // _Button_H_
