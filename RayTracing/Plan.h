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
	Plan(Vector3D p_position, float p_width, float p_height);
	float intersection(Ray& p_ray);
};
#endif