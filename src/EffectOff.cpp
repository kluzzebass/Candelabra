
#include <EffectOff.h>

void EffectOff::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = 1000;

	// Set all colors to black
	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[i].clear();
	}
}

bool EffectOff::update()
{
	if (!timeForUpdate()) return false;

	return true;
}