#include "Ray.h"

Ray::Ray(void):
	origin(Vector3D(0,0,0)), dir(Vector3D(1,1,1))
{
}

Ray::Ray(Vector3D p_origin, Vector3D p_dir):
	origin(p_origin), dir(p_dir)
{
}