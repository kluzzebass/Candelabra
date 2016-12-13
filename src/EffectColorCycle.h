
#ifndef _EffectColorCycle_h_
#define _EffectColorCycle_h_

#include <Effect.h>

class EffectColorCycle : public Effect
{
public:
	EffectColorCycle(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer, int bufferSize) override;
	void update() override;

protected:
	uint16_t sequencePosition = 0;
	uint16_t sequenceStep = 1;
	uint16_t sequenceSpeed = 1;
	bool reverse = false;
};

#endif // _EffectColorCycle_h_