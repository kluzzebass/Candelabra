
#ifndef _EffectTheaterChase_h_
#define _EffectTheaterChase_h_

#include <Effect.h>

class EffectTheaterChase : public Effect
{
public:
	EffectTheaterChase(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer) override;
	bool update() override;

protected:
	uint8_t chasePosition = 0;
	uint16_t sequencePosition = 0;
	uint16_t sequenceSpeed = 1;
	uint8_t density = 3;
	bool reverse = false;
};

#endif // _EffectTheaterChase_h_