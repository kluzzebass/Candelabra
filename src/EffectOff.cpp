
#include <EffectOff.h>

void EffectOff::init(Color *buffer, int bufferSize)
{
	this->buffer = buffer;
	this->bufferSize = bufferSize;

	// Set all colors to black
	for (int i = 0; i < bufferSize; i++)
	{
		buffer[i].clear();
	}
}

void EffectOff::update()
{
}