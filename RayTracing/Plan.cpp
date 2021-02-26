#include "Plan.h"

Plan::Plan(void):
	PrimitiveObject()
{
}

Plan::Plan(Vector3D p_position, Vector3D p_normal, Material p_material) :
	PrimitiveObject(), normal(p_normal.getNormalize())
{
	position = p_position;
	material = p_material;
}
Intersection* Plan::intersection(Ray& p_ray) {
	Vector3D diff = (this->position - p_ray.pos);
	float ndotrd = p_ray.dir.scalarProduct(this->normal); //ndotd <=> n.p_ray[dir]
	float t = -1;
	Intersection* new_intersection = NULL;
	if (ndotrd != 0.0f )
	{
		t = diff.scalarProduct(this->normal) / ndotrd;
		if (t >= 0) {
			Vector3D p = p_ray.pos + p_ray.dir * t;
			new_intersection = new Intersection(p, this->normal, 0, t);
		}
	}
	return new_intersection;
}

Color Plan::getColor(void)
{
	return material.color;
}