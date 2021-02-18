#ifndef _SPHERE_H_
#define _SPHERE_H_
#include <cmath>
#include "PrimitiveObject.h"

class Sphere : public PrimitiveObject
{
public:
	float radius;

	Sphere(void);
	Sphere(Vector3D p_position, float p_radius, Material p_material);
	~Sphere(void);
	virtual float intersection(Ray& p_ray);
	virtual Color lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection);
	virtual Color getColor(void);
};

#endif