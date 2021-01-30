#include "Sphere.h"

Sphere::Sphere(void):
	PrimitiveObject()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	std::cout << "here\n";
	radius = 1.0f;
	color = Color(255, 255, 255); //Color white by default
}

Sphere::Sphere(Vector3D p_position, float p_radius, Color p_color):
	PrimitiveObject()
{
	this->position = p_position;
	this->color = p_color;
	//Check if radius is positif
	if (radius >= 0) {
		radius = p_radius;
	}
	else {
		radius = -p_radius;
	}
}

Intersection* Sphere::intersection(Ray& p_ray)
{
	Intersection* intersection = NULL;
	Vector3D dist = p_ray.pos - this->position;
	//Calcul of discriminant (d), d = b�-4ac
	float a = p_ray.dir.scalarProduct(p_ray.dir); //Scalar product of ray direction vector (dir) -> dir.dir or 
	float b = 2.0 * dist.scalarProduct(p_ray.dir);
	float c = dist.scalarProduct(dist) - (this->radius * this->radius);
	float d = b * b - 4 * a * c;
	if (d == 0) { //Only one intersection
		float t = -b / 2 * a;

		intersection = new Intersection();
		intersection->position = p_ray.pos + p_ray.dir * t;
		intersection->normal = (intersection->position - this->position);
	}
	else if (d > 0) { //Two intersections, ray passes through the sphere
		float dSqrt = sqrt(d);
		float t1 = (-b - dSqrt) / 2 * a;
		float t2 = (-b + dSqrt) / 2 * a;
		float t = std::max(t1,t2);
		if (t > 0) {
			intersection = new Intersection();
			intersection->position = p_ray.pos + p_ray.dir * t;
			intersection->normal = (intersection->position - this->position);
		}
	}
	return intersection;
}