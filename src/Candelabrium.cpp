
#include <Candelabrium.h>

void Candelabrium::setup()
{
#ifdef USE_SERIAL
	Serial.begin(115200);
#endif
	randomSeed(analogRead(0));

	strip.begin();
	strip.setBrightness(brightnessLevels[brightness]);
	strip.show();

	priFx = effects[1];
	priFx->init(priBuf, LED_COUNT);
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

	if (button2.changed() && button2.pressed())
	{
		currentEffect = (currentEffect + 1) % ( sizeof(effects) / sizeof(effects[0]));
		priFx = effects[currentEffect];
		priFx->init(priBuf, LED_COUNT);
	}

	unsigned long now = millis();

	if (now < (lastTime + EFFECT_DELAY)) return;
	lastTime = now;

	priFx->update();

	for (int i = 0; i < LED_COUNT; i++)
	{
		strip.setPixelColor(i, priBuf[i].r, priBuf[i].g, priBuf[i].b);
	}
	strip.show();

}

void Candelabrium::changeBrightness()
{
	brightness = (brightness + 1) % BRIGHTNESS_LEVELS;

	uint8_t level = brightnessLevels[brightness];
	strip.setBrightness(level);
#ifdef USE_SERIAL
	Serial.print(F("Brightness set to level: "));
	Serial.print(brightness);
	Serial.print(F(" ("));
	Serial.print(level);
	Serial.println(F(")"));
#endif
}

void Candelabrium::togglePower()
{
	if (on)
	{
#ifdef USE_SERIAL
		Serial.println(F("Powering off."));
#endif
		on = false;
		strip.clear();
		strip.show();
	}
	else
	{
#ifdef USE_SERIAL
		Serial.println(F("Powering on."));
#endif
		on = true;
	}
}