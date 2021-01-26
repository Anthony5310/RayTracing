#include "Vector3D.h"

Vector3D::Vector3D(float p_x, float p_y, float p_z):
	x(p_x), y(p_y), z(p_z)
{
}

void Vector3D::display(void)
{
	std::cout << "[" << this->x << " " << this->y << " " << this->z << "]" << std::endl;
	return;
}

float Vector3D::norm(void)
{
	return sqrtf(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector3D Vector3D::operator+ (Vector3D p_vector) {
	return Vector3D(p_vector.x + x, p_vector.y + y, p_vector.z + z);
}