#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_
#include <iostream>
#include <math.h>

class Vector3D 
{
private:
	float x, y, z;
public:
	Vector3D(float p_x, float p_y, float p_z);
	void display(void);
	float norm(void);
};

#endif