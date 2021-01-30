#include "Intersection.h"

Intersection::Intersection(void)
{
	position = Vector3D(0, 0, 0);
	normal = Vector3D(0, 0, 0);
	objectId = 0;
}

Intersection::Intersection(Vector3D p_position, Vector3D p_normal, int p_objectId) {
	position = p_position;
	normal = p_normal;
	objectId = p_objectId;
}

Intersection::~Intersection(void)
{
	delete this;
}
