#include "PrimitiveObject.h"

PrimitiveObject::PrimitiveObject(void) :
	Object()
{
}

PrimitiveObject::~PrimitiveObject(void)
{
}

float PrimitiveObject::intersection(Ray& p_ray)
{
	return -1.0f;
}

Color PrimitiveObject::lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection)
{
	return Color(0, 0, 0);
}

Color PrimitiveObject::getColor(void)
{
	return Color(0, 0, 0);
}