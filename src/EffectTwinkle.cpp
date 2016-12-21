
#include <EffectTwinkle.h>

void EffectTwinkle::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = 25;

	// Set all colors to black
	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[i].clear();
	}

	for (int i = 0; i < TWINKLES; i++)
	{
		colors[i] = colorSequence(random(0, sequenceLength(true)), true);
		positions[i] = findUnusedPosition();
		progress[i] = -random(1, TWINKLE_MAX_DELAY);
	}
}

bool EffectTwinkle::update()
{
	if (!timeForUpdate()) return false;

	int p;

	for (int i = 0; i < LED_COUNT; i++)
		buffer[i].clear();

	for (int i = 0; i < TWINKLES; i++)
	{
		if (progress[i] >= 0)
		{
			if (progress[i] < TWINKLE_UP)
			{
				buffer[positions[i]] = buffer[positions[i]].fadeTo(colors[i], progress[i], TWINKLE_UP);
			}
			else if (progress[i] < (TWINKLE_UP + TWINKLE_STAY))
			{
				buffer[positions[i]] = colors[i];
			}
			else
			{
				buffer[positions[i]] = colors[i].fadeTo(buffer[positions[i]], progress[i] - TWINKLE_STAY - TWINKLE_UP, TWINKLE_DOWN);
			}
		}
		progress[i]++;

		if (progress[i] >= TWINKLE_TOTAL)
		{
			colors[i] = colorSequence(random(0, sequenceLength(true)), true);
			positions[i] = findUnusedPosition();
			progress[i] = -random(1, TWINKLE_MAX_DELAY);
		}
	}

	return true;
}


// Non-deterministic as fuck, so don't set the number of TWINKLES too high.
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
	return 0; // Odds are quite low that this will ever be reached.
}