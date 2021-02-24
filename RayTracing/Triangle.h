#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "PrimitiveObject.h"

class Triangle : public PrimitiveObject
{
public:
	//3 points délimitants le triangle
	Vector3D p0;
	Vector3D p1;
	Vector3D p2;

	Triangle(void);

};

#endif