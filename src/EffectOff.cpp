
#include <EffectOff.h>

void EffectOff::init(Color *buffer, int bufferSize)
{
	Serial.println("EffectOff::init");
	this->buffer = buffer;
	this->bufferSize = bufferSize;

	// Set all colors to black
	for (int i = 0; i < bufferSize; i++)
	{
		buffer[i].r = 0;
		buffer[i].g = 0;
		buffer[i].b = 0;
	}
}

void EffectOff::update()
{
	// This effect does nothing.
	Serial.println("EffectOff::init");
}