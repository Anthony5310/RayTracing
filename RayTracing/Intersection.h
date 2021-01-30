#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_
#include <iostream>
#include "Vector3D.h"

class Intersection 
{
public:
	Vector3D position;
	Vector3D normal;

	Intersection(void);
	Intersection(Vector3D p_position, Vector3D p_normal);
};

#endif
