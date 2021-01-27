#include "Sphere.h"

Sphere::Sphere(void)
{
	center = Vector3D(0.0f, 0.0f, 0.0f);
	radius = 1.0f;
	color = Color(255, 255, 255);
}

Sphere::Sphere(Vector3D p_center, float p_radius, Color p_color)