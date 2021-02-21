#include "Plan.h"

Plan::Plan(void):
	PrimitiveObject()
{
	width = 1.0;
	height = 1.0;
}

Plan::Plan(Vector3D p_position, float p_width, float p_height, Vector3D p_normal, Material p_material) :
	PrimitiveObject(), width(p_width), height(p_height), normal(p_normal)
{
	position = p_position;
	material = p_material;
}
float Plan::intersection(Ray& p_ray) {
	Vector3D diff = (this->position - p_ray.pos).getNormalize();
	float ndotrd = p_ray.dir.scalarProduct(this->normal); //ndotd <=> n.p_ray[dir]
	float t = -1;
	if (ndotrd != 0.0 )
	{
		t = diff.scalarProduct(this->normal) / ndotrd;
		if (t >= 0) {
			Vector3D p = p_ray.pos + p_ray.dir * t;
			
			/*
			if (!isInPlan(p)) {
				t = -1;
			}*/
		}
	}
	return t;
}

Color Plan::lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection)
{
	return material.color;
}

Color Plan::getColor(void)
{
	return material.color;
}

bool Plan::isInPlan(Vector3D p_point) 
{
	Vector3D diff(p_point.x - this->position.x, p_point.y - this->position.y, 0.0f);
	if (diff.x < 0)
		diff.x = -diff.x;
	if (diff.y < 0)
		diff.y = -diff.y;
	if (diff.x >= this->width / 2 || diff.y >= this->height / 2) {
		return false;
	}
	return true;
}