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
	return sqrtf(x*x + y*y + z*z);
}

void Vector3D::normalize(void) 
{
	float norm = this->norm();
	x = x / norm;
	y = y / norm;
	z = z / norm;
}

Vector3D Vector3D::getNormalize(void)
{
	Vector3D result(*this);
	result.normalize();
	return result;
}

float Vector3D::scalarProduct(Vector3D p_vector)
{
	return (this->x * p_vector.x + this->y * p_vector.y + this->z * p_vector.z);
}

float Vector3D::scalarProduct(float p_scalar)
{
	return (this->x * p_scalar + this->y * p_scalar + this->z * p_scalar);
}

Vector3D Vector3D::operator+ (Vector3D p_vector) {
	return Vector3D(
		p_vector.x + x, 
		p_vector.y + y, 
		p_vector.z + z);
}

Vector3D Vector3D::operator+ (float p_scalar)
{
	return Vector3D(
		p_scalar + x,
		p_scalar + y,
		p_scalar + z);
}

Vector3D Vector3D::operator- (Vector3D p_vector) {
	return Vector3D(
		x - p_vector.x,
		y - p_vector.y,
		z - p_vector.z);
}

Vector3D Vector3D::operator/ (float p_scalar) {
	return Vector3D(
		x / p_scalar,
		y / p_scalar,
		z / p_scalar);
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

Vector3D Vector3D::operator* (Color p_color) 
{
	return Vector3D(
		p_color.r * x,
		p_color.g * y,
		p_color.b * z
	);
}
Vector3D Vector3D::operator^ (Vector3D p_vector) {
	return Vector3D(
		p_vector.z * y - p_vector.y * z,
		p_vector.x * z - p_vector.z * x,
		p_vector.y * x - p_vector.x * y);
}

Vector3D Vector3D::reflect(Vector3D p_normal) {
	return (*this) - (p_normal * this->scalarProduct(p_normal) * 2);
}

Color Vector3D::toColor(void) {
	Color color((unsigned char)x, (unsigned char)y, (unsigned char)z);
	color.clamp();
	return color;
}