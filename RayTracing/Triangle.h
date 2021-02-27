#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <cmath>
#include "PrimitiveObject.h"


class Triangle : public PrimitiveObject
{
public:
	//3 points délimitants le triangle
	Vector3D p0;
	Vector3D p1;
	Vector3D p2;

	Triangle(void);
	Triangle(Vector3D p_p0, Vector3D p_p1, Vector3D p_p2, Material p_material);
	Intersection* intersection(Ray& p_ray);
	Color getColor(void);
};

#endif