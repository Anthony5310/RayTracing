#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Ray.h"
#include "Intersection.h"

class Object
{
public:
	Vector3D position;
	Vector3D rotation;

	Object();
	~Object();
	virtual std::vector<Intersection*> intersections(Ray& p_ray)=0;
};
#endif