
#include <Candelabra.h>

Candelabra::Candelabra()
{

}

void Candelabra::setup()
{
	pinMode(BUTTON1_PIN, INPUT_PULLUP);
	pinMode(BUTTON2_PIN, INPUT_PULLUP);
	btn1.delay = DEBOUNCE_DELAY;
	btn2.delay = DEBOUNCE_DELAY;

	Serial.begin(115200);

	strip.begin();
	strip.show();
}

void Candelabra::loop()
{
	btn1.update(!digitalRead(BUTTON1_PIN));
	btn2.update(!digitalRead(BUTTON2_PIN));

	if (btn1.changed || btn2.changed)
	{
		Serial.print(F("Buttons: "));
		Serial.print(btn1.state);
		Serial.print(F(", "));
		Serial.println(btn2.state);
	}

	if (btn1.changed && btn1.state)
		changeBrightness();
}

void Candelabra::changeBrightness()
{
	brightness = (brightness + 1) % BRIGHTNESS_LEVELS;

	uint8_t level = pgm_read_byte_near(brightnessLevels + brightness);
	strip.setBrightness(level);
	Serial.print(F("Brightness set to level: "));
	Serial.print(brightness);
	Serial.print(F(" ("));
	Serial.print(level);
	Serial.println(F(")"));
}