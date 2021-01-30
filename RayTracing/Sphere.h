#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <iostream>
#include <cmath>
#include "PrimitiveObject.h"
#include "Color.h"

class Sphere : public PrimitiveObject
{
public:
	float radius;
	Color color;

	Sphere(void);
	Sphere(Vector3D p_position, float p_radius, Color p_color);
	Intersection* intersection(Ray& p_ray);
};

#endif