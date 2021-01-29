#include "Sphere.h"

Sphere::Sphere(void):
	Object()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	radius = 1.0f;
	color = Color(255, 255, 255); //Color white by default
}

Sphere::Sphere(Vector3D p_position, float p_radius, Color p_color):
	Object()
{
	this->position = position;
	this->color = p_color;
	//Check if radius is positif
	if (radius >= 0) {
		radius = p_radius;
	}
	else {
		radius = -p_radius;
	}
}