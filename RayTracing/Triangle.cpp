#include "Triangle.h"

Triangle::Triangle(void):
	PrimitiveObject()
{
	p0 = Vector3D(0, 0, 0);
	p1 = Vector3D(0, 1, 0);
	p2 = Vector3D(1, 0, 0);
}