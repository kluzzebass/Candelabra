
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

	currentEffect = random(0, fxCount);
	priFx = effects[currentEffect];
	priFx->init(buffers[0]);
}



void Candelabrium::loop()
{
	button1.update();
	button2.update();
	//Effect::shimmerUpdate();

	now = millis();

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
		if (!transitioning)
		{
			cycling = false;
			startTransition();
		}
	}

	if (button2.changed() && button2.longPressed())
	{
#ifdef USE_SERIAL
		Serial.println(F("Switching to automatic randomized transitions"));
#endif
		cycling = true;
		if (!transitioning)
		{
			startTransition();
		}
	}

	if (cycling && (now >= (lastTime + EFFECT_RUN_TIME)))
	{
		lastTime = now;
		startTransition();
	}

	unsigned long diff = 0;

	if (transitioning)
	{
		diff = now - transitionStart;

		if (diff >= EFFECT_TRANSITION_TIME)
		{
#ifdef USE_SERIAL
			Serial.println(F("Transition complete"));
#endif
			transitioning = false;
			priFx = secFx;
			secFx = nullptr;
			transitionStart = 0;
			diff = 0;
		}
	}

	bool updated = false;

	updated |= priFx->update();

	if (transitioning)
	{
		updated |= secFx->update();
		if (!updated) return;

		for (int i = 0; i < LED_COUNT; i++)
		{
			Color faded = priFx->buffer[i].fadeTo(secFx->buffer[i], diff, EFFECT_TRANSITION_TIME);
			strip.setPixelColor(i,
#ifdef GAMMA_CORRECTION
				pgm_read_byte(&gamma[faded.r]),
				pgm_read_byte(&gamma[faded.g]),
				pgm_read_byte(&gamma[faded.b])
#else
				faded.r,
				faded.g,
				faded.b
#endif
			);
		}
	}
	else
	{
		if (!updated) return;
		for (int i = 0; i < LED_COUNT; i++)
		{
			strip.setPixelColor(i,
#ifdef GAMMA_CORRECTION
				pgm_read_byte(&gamma[priFx->buffer[i].r]),
				pgm_read_byte(&gamma[priFx->buffer[i].g]),
				pgm_read_byte(&gamma[priFx->buffer[i].b])
#else
				priFx->buffer[i].r,
				priFx->buffer[i].g,
				priFx->buffer[i].b
#endif
			);
		}
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
		Serial.println(F("Powering off"));
#endif
		on = false;
		strip.clear();
		strip.show();
	}
	else
	{
#ifdef USE_SERIAL
		Serial.println(F("Powering on"));
#endif
		on = true;
	}
}

void Candelabrium::startTransition()
{
	uint8_t nextEffect;

	transitioning = true;
	transitionStart = now;

	do // Because screw determinism.
	{
		if (cycling)
			nextEffect = random(0, fxCount);
		else
			nextEffect = (currentEffect + 1) % fxCount;
	}
	while (nextEffect == currentEffect);

#ifdef USE_SERIAL
		Serial.print(F("Starting transition to effect "));
		Serial.println(nextEffect);
#endif

	currentEffect = nextEffect;
	secFx = effects[currentEffect];

	currentBuffer = (currentBuffer + 1) % BUFFERS;
	secFx->init(buffers[currentBuffer]);
}





