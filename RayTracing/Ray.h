#ifndef _RAY_H_
#define _RAY_H_
#include <iostream>
#include "Vector3D.h"

class Ray
{
public:
	Vector3D origin;	//Vector origin
	Vector3D dir;		//Vector direction

	Ray(void);
	Ray(Vector3D p_origin, Vector3D p_dir);
};
#endif