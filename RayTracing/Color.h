#ifndef _COLOR_H_
#define _COLOR_H_
#include <iostream>

class Color
{
public:
	Color(void);//Default: white
	Color(char p_r, char p_g, char p_b);
	char r, g, b;
};
#endif