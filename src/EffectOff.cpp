
#include <EffectOff.h>

void EffectOff::init(Color *buffer, int bufferSize)
{
	this->buffer = buffer;
	this->bufferSize = bufferSize;
	this->lastTime = 0;
	this->effectDelay = 1000;

	// Set all colors to black
	for (int i = 0; i < bufferSize; i++)
	{
		buffer[i].clear();
	}
}

bool EffectOff::update()
{
	if (!timeForUpdate()) return false;

	return true;
}