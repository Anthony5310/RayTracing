#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "Object.h"

class Light : public Object
{
public:
	Color color;
	Light();
	Light(Vector3D p_position, Color p_color);
};
#endif // !_LIGHT_H_
