#include "Vector3D.h"

Vector3D::Vector3D(float p_x, float p_y, float p_z) 
{
	this->x = p_x;
	this->y = p_y;
	this->z = p_z;
}

void Vector3D::displayVector3D(void)
{
	std::cout << "[ " << this->x << ", " << this->y << ", " << this->z << " ]" << std::endl;
	return;
}