#ifndef _PLAN_H_
#define _PLAN_H_
#include "PrimitiveObject.h"

class Plan : public PrimitiveObject
{
public:
	Vector3D normal;

	Plan(void);
	Plan(Vector3D p_position, Vector3D p_normal, Material p_material);
	Intersection* intersection(Ray& p_ray);
	Color getColor(void);
};
#endif