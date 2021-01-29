#include "Intersection.h"

Intersection::Intersection(void)
{
	position = Vector3D(0, 0, 0);
}

Intersection::Intersection(Vector3D p_position) {
	position = p_position;
}

