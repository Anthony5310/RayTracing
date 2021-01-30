#include "Intersection.h"

Intersection::Intersection(void)
{
	position = Vector3D(0, 0, 0);
	normal = Vector3D(0, 0, 0);
}

Intersection::Intersection(Vector3D p_position, Vector3D p_normal) {
	position = p_position;
	normal = p_normal;
}

