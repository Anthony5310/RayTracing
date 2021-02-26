#include "Sphere.h"

Sphere::Sphere(void):
	PrimitiveObject()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	radius = 1.0f;
}

Sphere::Sphere(Vector3D p_position, float p_radius, Material p_material):
	PrimitiveObject()
{
	this->position = p_position;
	this->material = p_material;
	//Check if radius is positif
	if (radius >= 0) {
		radius = p_radius;
	}
	else {
		radius = -p_radius;
	}
}

Sphere::~Sphere(void) {
	delete this;
}

Intersection* Sphere::intersection(Ray& p_ray)
{
	Vector3D dist = p_ray.pos - this->position;
	Intersection* new_intersection = NULL;
	//Calcul of discriminant (d), d = b²-4ac
	float a = p_ray.dir.scalarProduct(p_ray.dir); //Scalar product of ray direction vector (dir) -> dir.dir or 
	//float a = 1;
	float b = 2.0 * dist.scalarProduct(p_ray.dir);
	float c = dist.scalarProduct(dist) - (this->radius * this->radius);
	float d = b * b - 4 * a * c;
	float t = -1.0f;
	if (d == 0) { //Only one intersection
		t = -b / 2 * a;
	}
	else if (d > 0) { //Two intersections, ray passes through the sphere
		float dSqrt = sqrt(d);
		float t1 = (-b - dSqrt) / 2 * a;
		float t2 = (-b + dSqrt) / 2 * a;
		if (t1 > 0) {
			t = t1;
		}
		else {
			t = t2;
		}
	}
	if (t >= 0) {
		Vector3D intersection_pos = p_ray.pos + p_ray.dir * t;
		Vector3D intersection_normal = (intersection_pos - this->position).getNormalize();
		new_intersection = new Intersection(intersection_pos, intersection_normal, 0, t);
	}	
	return new_intersection;
}

Color Sphere::getColor(void)
{
	return material.color;
}

