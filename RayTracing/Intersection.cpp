#include "Intersection.h"

Intersection::Intersection(void)
{
	position = Vector3D(0, 0, 0);
	normal = Vector3D(0, 0, 0);
	objectId = 0;
	t = 0.0f;
}

Intersection::Intersection(Vector3D p_position, Vector3D p_normal, int p_objectId, float p_t) {
	position = p_position;
	normal = p_normal;
	objectId = p_objectId;
	t = p_t;
}

Intersection::~Intersection(void)
{
	delete this;
}
