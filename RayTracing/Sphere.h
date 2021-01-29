#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <iostream>
#include <cmath>
#include "Object.h"
#include "Vector3D.h"
#include "Color.h"

class Sphere : public Object
{
public:
	float radius;
	Color color;

	Sphere();
	Sphere(Vector3D p_position, float p_radius, Color p_color);
	std::vector<Intersection> intersections(Ray& p_ray);
};

#endif