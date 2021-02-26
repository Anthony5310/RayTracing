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
	float rf, gf, bf;
	rf = r * p_scalar;
	gf = g * p_scalar;
	bf = b * p_scalar;
	rf = std::min(255.0f, std::max(rf, 0.0f));
	gf = std::min(255.0f, std::max(gf, 0.0f));
	bf = std::min(255.0f, std::max(bf, 0.0f));
	return Color(
		rf,
		gf,
		bf);
}

Color Color::operator+(Color p_color) {
	float rf, gf, bf;
	rf = r + p_color.r;
	gf = g + p_color.g;
	bf = b + p_color.b;
	rf = std::min(255.0f, std::max(rf, 0.0f));
	gf = std::min(255.0f, std::max(gf, 0.0f));
	bf = std::min(255.0f, std::max(bf, 0.0f));
	return Color(
		rf,
		gf,
		bf);
}

