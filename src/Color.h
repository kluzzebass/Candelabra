
#ifndef _Color_h_
#define _Color_h_

class Color
{
public:
	Color() {}
	Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

	Color fadeTo(Color destination, uint32_t numerator, uint32_t denominator)
	{
		if (!denominator) denominator = 1;
		if (numerator > denominator) numerator = denominator;
		uint8_t new_r = ((uint32_t)r * numerator)/denominator;
		uint8_t new_g = ((uint32_t)g * numerator)/denominator;
		uint8_t new_b = ((uint32_t)b * numerator)/denominator;

		return Color(new_r, new_g, new_b);
	}

	uint8_t r, g, b;
};

#endif // _Color_