#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
#include "Vector3D.h"

class Object
{
public:
	Vector3D position;
	Vector3D rotation;

	Object();
};
#endif