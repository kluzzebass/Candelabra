
#include <EffectPendulum.h>

void EffectPendulum::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = 20;

	for (int i = 0; i < 6; i++)
	{
		angles[i] = M_PI * (float)random(0, 100) / (float)50;
		speeds[i] = (float)random(1, 10) / (float)100;
	}
}

bool EffectPendulum::update()
{
	if (!timeForUpdate()) return false;

	clear();

	uint8_t positions[3];

	for (int i = 0; i < 3; i++)
	{
		positions[i] = round(
			(
				(
					(
						sin(angles[i * 2]) + sin(angles[i * 2 + 1]) + 2
					) / 2
				) * (double)(
					LED_COUNT - sizeof(pendulum)
				)
			) / 2
		);
	}

	for (int i = 0; i < sizeof(pendulum); i++)
	{
		buffer[i + positions[0]].r = pendulum[i];
		buffer[i + positions[1]].g = pendulum[i];
		buffer[i + positions[2]].b = pendulum[i];
	}

	for (int i = 0; i < 6; i++)
	{
		angles[i] += speeds[i];
		angles[i] = fmod(angles[i], 2 * M_PI);
	}

	return true;
}