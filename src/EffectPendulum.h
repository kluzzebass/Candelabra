
#ifndef _EffectPendulum_h_
#define _EffectPendulum_h_

#include <Effect.h>

class EffectPendulum : public Effect
{
public:
	EffectPendulum(const uint8_t (&map)[LED_COUNT]) : Effect(map) {}

	void init(Color *buffer) override;
	bool update() override;

protected:
	uint8_t pendulum[7] = { 10, 30, 150, 255, 150, 30, 10 };
	double angles[6];
	double speeds[6];

};

#endif // _EffectPendulum_h_