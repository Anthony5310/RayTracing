#include "Intersection.h"

Intersection::Intersection(void)
{
}

bool Intersection::touch(Ray& p_ray, Object p_object)
{
	std::cout << "Intersection !!" << std::endl;
	Vector3D a = p_ray.dir * p_ray.dir;
}