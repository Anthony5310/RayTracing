#ifndef _COLOR_H_
#define _COLOR_H_
#include <iostream>
#include <algorithm>

class Color
{
public:
	unsigned char r, g, b;

	Color(void);//Default: white
	Color(char p_r, char p_g, char p_b);
	Color operator*(float p_scalar);
	Color operator+(Color p_color);
};
#endif