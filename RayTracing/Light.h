#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "Object.h"

class Light : public Object
{
public:
	Color color;
	Light();
};
#endif // !_LIGHT_H_
