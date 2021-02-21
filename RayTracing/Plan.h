#ifndef _PLAN_H_
#define _PLAN_H_
#include "PrimitiveObject.h"

class Plan : public PrimitiveObject
{
public:
	float width;
	float height;
	Vector3D normal;

	Plan(void);
	Plan(Vector3D p_position, float p_width, float p_height, Vector3D p_normal, Material p_material);
	float intersection(Ray& p_ray);
	Color lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection);
	Color getColor(void);
	bool isInPlan(Vector3D p_point);
};
#endif