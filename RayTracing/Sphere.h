#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <iostream>
#include "Vector3D.h"
#include "Color.h"

class Sphere
{
public:
	Vector3D center;
	float radius;
	Color color;

	Sphere();
	Sphere(Vector3D p_center, float p_radius, Color p_color);
};

#endif