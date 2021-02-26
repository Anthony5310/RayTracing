#include "Color.h"

Color::Color(void) :
	r(255), g(255), b(255)
{
}


Color::Color(char p_r, char p_g, char p_b):
	r(p_r), g(p_g), b(p_b)
{
}

void Color::clamp(void)
{
	if (r < 0) 
	{
		 r = 0;
	}
	if (g < 0)
	{
		 g = 0;
	}
	if (b < 0)
	{
		 b = 0;
	}
	if (r > 255)
	{
		 r = 255;
	}
	if (g > 255)
	{
		 g = 255;
	}
	if (b > 255)
	{
		 b = 255;
	}
}

Color Color::operator*(float p_scalar) {
	return Color(
		r * p_scalar,
		g * p_scalar,
		b * p_scalar);
}

Color Color::operator+(Color p_color) {
	return Color(
		r + p_color.r,
		g + p_color.g,
		b + p_color.b);
}