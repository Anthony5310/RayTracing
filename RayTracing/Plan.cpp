#include "Plan.h"

Plan::Plan(void):
	PrimitiveObject()
{
	width = 1.0;
	height = 1.0;
}

Plan::Plan(Vector3D p_position, float p_width, float p_height) :
	PrimitiveObject(), width(p_width), height(p_height)
{
	position = p_position;
}
float Plan::intersection(Ray& p_ray) {
	Vector3D distance = p_ray.pos - this->position;
	float t = distance.scalarProduct(this->normal) / p_ray.dir.scalarProduct(this->normal);
	return t;
}
