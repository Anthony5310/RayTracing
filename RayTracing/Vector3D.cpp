#include "Vector3D.h"

Vector3D::Vector3D(void):
	x(1), y(1), z(1)
{
}
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

void Vector3D::normalize(void) 
{
	float norm = this->norm();
	x = x / norm;
	y = y / norm;
	z = z / norm;
}

Vector3D Vector3D::scalarProduct(Vector3D p_vector1, Vector3D p_vector2)
{
	return (p_vector1.x * p_vector2.x + p_vector1.y * p_vector2.y + p_vector1.z * p_vector2.z);
}

float Vector3D::scalarProduct(Vector3D p_vector1, float p_scalar)
{
	return (p_vector1.x * p_scalar + p_vector1.y * p_scalar + p_vector1.z * p_scalar);
}

Vector3D Vector3D::operator+ (Vector3D p_vector) {
	return Vector3D(
		p_vector.x + x, 
		p_vector.y + y, 
		p_vector.z + z);
}

Vector3D Vector3D::operator- (Vector3D p_vector) {
	return Vector3D(
		x - p_vector.x,
		y - p_vector.y,
		z - p_vector.z);
}

Vector3D Vector3D::operator* (Vector3D p_vector) {
	return Vector3D(
		p_vector.x * x, 
		p_vector.y * y, 
		p_vector.z * z);
}

Vector3D Vector3D::operator* (float p_scalar) {
	return Vector3D(
		p_scalar * x,
		p_scalar * y,
		p_scalar * z);
}

Vector3D Vector3D::operator^ (Vector3D p_vector) {
	return Vector3D(
		p_vector.z * y - p_vector.y * z,
		p_vector.x * z - p_vector.z * x,
		p_vector.y * x - p_vector.x * y);
}