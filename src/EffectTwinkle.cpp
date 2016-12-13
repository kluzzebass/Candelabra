
#include <EffectTwinkle.h>

void EffectTwinkle::init(Color *buffer, int bufferSize)
{
	this->buffer = buffer;
	this->bufferSize = bufferSize;

	// Set all colors to black
	for (int i = 0; i < bufferSize; i++)
	{
		buffer[i].clear();
	}

	for (int i = 0; i < TWINKLES; i++)
	{
		colors[i] = colorSequence(random(0, sequenceLength(true)), true);
		positions[i] = random(0, LED_COUNT);
		progress[i] = -random(1, TWINKLE_MAX_DELAY);
	}
}

void EffectTwinkle::update()
{
	int p;
	Color c, black = Color(0, 0, 0);


	for (int i = 0; i < bufferSize; i++) buffer[i].clear();

	for (int i = 0; i < TWINKLES; i++)
	{
		if (progress[i] >= 0)
		{
			if (progress[i] < TWINKLE_UP)
			{
				c = black.fadeTo(colors[i], progress[i], TWINKLE_UP);
			}
			else if (progress[i] < (TWINKLE_UP + TWINKLE_STAY))
			{
				c = colors[i];
			}
			else
			{
				c = colors[i].fadeTo(black, progress[i] - TWINKLE_STAY - TWINKLE_UP, TWINKLE_DOWN);
			}

			buffer[positions[i]] = c;
		}
		progress[i]++;

		if (progress[i] >= TWINKLE_TOTAL)
		{
			colors[i] = colorSequence(random(0, sequenceLength(true)), true);
			positions[i] = findUnusedPosition();
			progress[i] = -random(1, TWINKLE_MAX_DELAY);
		}
	}
}


// Non-deterministic as fuck, so don't set the TWINKLES too high.
uint8_t EffectTwinkle::findUnusedPosition()
{
	uint8_t pos;
	bool used;

	for (int j = 0; j< 10; j++)
	{
		pos = random(0, LED_COUNT);
		used = false;
		for (int i = 0; i < TWINKLES; i++)
		{
			if (positions[i] == pos) used = true; 
		}
		if (!used) return pos;
	}
	Serial.println("Ran out of attempts!");
	return 0;
}