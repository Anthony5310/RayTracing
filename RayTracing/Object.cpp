#include "Object.h"

Object::Object(void) :
	position(Vector3D(0, 0, 0)), rotation(Vector3D(0, 0, 0))
{
}

std::vector<Intersection> Object::intersections(Ray& p_ray) 
{
}