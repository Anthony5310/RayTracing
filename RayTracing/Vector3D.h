#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_
#include <iostream>

class Vector3D 
{
public:
	float x;
	float y;
	float z;

	Vector3D(float p_x, float p_y, float p_z);
	void displayVector3D(void);
};

#endif