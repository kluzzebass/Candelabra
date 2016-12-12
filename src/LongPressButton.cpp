

#include <LongPressButton.h>

LongPressButton::LongPressButton(int pin, int delay, int holdTime) : pin(pin), holdTime(holdTime)
{
	pinMode(pin, INPUT_PULLUP);
	debouncer.delay = delay;
}

void LongPressButton::update()
{
	debouncer.update(!digitalRead(pin));

	hasChanged = false;
	unsigned long now = millis();

	if (debouncer.changed)
	{
//		Serial.println("state changed");
		if (debouncer.state)
		{
//			Serial.println("starting hold");
			holdStart = now;
			isPressed = true;
			hasChanged = true;
		}
		else
		{
//			Serial.println("ending hold");
			holdStart = 0;
			isLongPressed = false;
			isPressed = false;
			hasChanged = true;
		}
	}
	else
	{
		if (debouncer.state && !isLongPressed && now > (holdStart + holdTime))
		{
//			Serial.println("long press detected");
			isLongPressed = true;
			isPressed = false;
			hasChanged = true;
		}
	}
}