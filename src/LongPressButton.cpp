
#include <LongPressButton.h>

LongPressButton::LongPressButton(uint8_t pin, uint16_t delay, uint16_t holdTime) : pin(pin), holdTime(holdTime)
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
		if (debouncer.state)
		{
			holdStart = now;
			isPressed = true;
			hasChanged = true;
		}
		else
		{
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
			isLongPressed = true;
			isPressed = false;
			hasChanged = true;
		}
	}
}