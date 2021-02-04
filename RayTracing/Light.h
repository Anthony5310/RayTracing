#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "Object.h"

class Light : public Object
{
public:
	Vector3D color;
	Vector3D ambiantColor;
	Vector3D diffuseColor;
	Vector3D specularColor;
	float power;

	Light();
};
#endif // !_LIGHT_H_
