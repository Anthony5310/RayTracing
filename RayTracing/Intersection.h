#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_
#include <iostream>
#include "Ray.h"
#include "Object.h"

class Intersection 
{
public:
	Intersection(void);
	static bool touch(Ray &p_ray, Object p_object);
};
#endif // !_INTERSECTION_H_
