#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <iostream>
#include <cmath>
#include "PrimitiveObject.h"

class Sphere : public PrimitiveObject
{
public:
	float radius;
	Color color;

	Sphere(void);
	Sphere(Vector3D p_position, float p_radius, Color p_color);
	~Sphere(void);
	virtual float intersection(Ray& p_ray);
	virtual Color lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection);
	virtual Color getColor(void);
};

#endif