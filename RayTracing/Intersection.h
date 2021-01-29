#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_
#include <iostream>
#include "Vector3D.h"
#include "Ray.h"
#include "Sphere.h"

class Intersection 
{
public:
	Intersection(void);
	static bool touch(Ray& p_ray, Object* p_object);
};

#endif
