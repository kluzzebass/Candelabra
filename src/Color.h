
#ifndef _Color_h_
#define _Color_h_

class Color
{
public:
	Color() {}
	Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

	void clear() { r = 0; g = 0; b = 0; }
	Color fadeTo(Color destination, int32_t numerator, int32_t denominator)
	{
		if (!denominator) denominator = 1;
		if (numerator > denominator) numerator = denominator;

		int32_t delta_r = destination.r - r;
		int32_t delta_g = destination.g - g;
		int32_t delta_b = destination.b - b;

		uint8_t new_r = r + ((delta_r * numerator)/denominator);
		uint8_t new_g = g + ((delta_g * numerator)/denominator);
		uint8_t new_b = b + ((delta_b * numerator)/denominator);

		return Color(new_r, new_g, new_b);
	}

	uint8_t r = 0, g = 0, b = 0;
};

#endif // _Color_