
#ifndef _EffectOff_h_
#define _EffectOff_h_

#include <Effect.h>

class EffectOff : public Effect
{
public:
	EffectOff(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer, int bufferSize) override;
	void update() override;
};

#endif // _EffectOff_h_