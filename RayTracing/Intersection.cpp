#include "Intersection.h"

Intersection::Intersection(void)
{
}

bool Intersection::touch(Ray& p_ray, Object* p_object)
{
	Vector3D dist = p_ray.pos - p_object->position;
	float a = p_ray.dir.scalarProduct(p_ray.dir); //Scalar product of ray direction vector (dir) -> dir.dir or 
	float b = 2.0 * dist.scalarProduct(p_ray.dir);
	p_object->type();
	
	return false;
}