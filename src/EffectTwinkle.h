
#ifndef _EffectTwinkle_h_
#define _EffectTwinkle_h_

#include <Effect.h>

#define TWINKLES 8
#define TWINKLE_UP 10
#define TWINKLE_STAY 3
#define TWINKLE_DOWN 30
#define TWINKLE_TOTAL TWINKLE_UP + TWINKLE_STAY + TWINKLE_DOWN
#define TWINKLE_MAX_DELAY 30

class EffectTwinkle : public Effect
{
public:
	EffectTwinkle(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer, int bufferSize) override;
	void update() override;

protected:
	Color colors[TWINKLES];
	uint8_t positions[TWINKLES];
	int8_t progress[TWINKLES];

	uint8_t findUnusedPosition();

};

#endif // _EffectTwinkle_h_