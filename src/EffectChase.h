
#ifndef _EffectChase_h_
#define _EffectChase_h_

#include <Effect.h>

class EffectChase : public Effect
{
public:
	EffectChase(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer, int bufferSize) override;
	void update() override;

protected:
	uint8_t pixelPosition = 0;
	uint8_t tailLength = 3;
	uint16_t sequencePosition = 0;
	uint16_t sequenceStep = 1;
	uint16_t sequenceSpeed = 1;
	bool reverse = false;

};

#endif // _EffectChase_h_
