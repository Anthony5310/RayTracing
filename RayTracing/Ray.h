#ifndef _RAY_H_
#define _RAY_H_
#include <iostream>
#include "Vector3D.h"

class Ray
{
public:
	Vector3D pos;	//Vector origin
	Vector3D dir;	//Vector direction

	Ray(void);
	Ray(Vector3D p_pos, Vector3D p_dir);
	void setPos(Vector3D p_pos);
	void setDir(Vector3D p_dir);
	void display(void);
};
#endif