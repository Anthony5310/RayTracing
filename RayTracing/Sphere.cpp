#include "Sphere.h"

Sphere::Sphere(void)
{
	center = Vector3D(0.0f, 0.0f, 0.0f);
	radius = 1.0f;
	color = Color(255, 255, 255); //Color white by default
}

Sphere::Sphere(Vector3D p_center, float p_radius, Color p_color) :
	center(p_center), color(p_color)
{
	//Check if radius is positif
	if (radius >= 0) {
		radius = p_radius;
	}
	else {
		radius = -p_radius;
	}
}