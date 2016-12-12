
#include <Candelabrium.h>

Candelabrium::Candelabrium()
{

}

void Candelabrium::setup()
{
	Serial.begin(115200);

	strip.begin();
	strip.show();
}

void Candelabrium::loop()
{
	button1.update();
	button2.update();

	if (!on)
	{
		// Any short button press will turn the power on again...
		if ((button1.changed() && button1.pressed()) || (button2.changed() && button2.pressed()))
			togglePower();

		// ...but we'll still exit this loop() call.
		return;
	}

	if (button1.changed() && button1.pressed())
		changeBrightness();

	if (button1.changed() && button1.longPressed())
		togglePower();

}

void Candelabrium::changeBrightness()
{
	brightness = (brightness + 1) % BRIGHTNESS_LEVELS;

	uint8_t level = brightnessLevels[brightness];
	strip.setBrightness(level);
	Serial.print(F("Brightness set to level: "));
	Serial.print(brightness);
	Serial.print(F(" ("));
	Serial.print(level);
	Serial.println(F(")"));
}

void Candelabrium::togglePower()
{
	if (on)
	{
		Serial.println(F("Powering off."));
		on = false;
		strip.clear();
		strip.show();
	}
	else
	{
		Serial.println(F("Powering on."));
		on = true;
	}
}