#include "Sphere.h"

Sphere::Sphere(void):
	Object()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	std::cout << "here\n";
	radius = 1.0f;
	color = Color(255, 255, 255); //Color white by default
}

Sphere::Sphere(Vector3D p_position, float p_radius, Color p_color):
	Object()
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

std::vector<Intersection*> Sphere::intersections(Ray& p_ray)
{
	std::vector<Intersection*> list;
	list.clear();
	Vector3D dist = p_ray.pos - this->position;
	//Calcul of discriminant (d), d = b�-4ac
	float a = p_ray.dir.scalarProduct(p_ray.dir); //Scalar product of ray direction vector (dir) -> dir.dir or 
	float b = 2.0 * dist.scalarProduct(p_ray.dir);
	float c = dist.scalarProduct(dist) - (this->radius * this->radius);
	float d = b * b - 4 * a * c;
	if (d == 0) { //Only one intersection
		float t = -b / 2 * a;
		list.push_back(new Intersection(p_ray.pos + p_ray.dir * t));
		std::cout << "1 intersection" << std::endl;
	}
	else if (d > 0) { //Two intersections, ray passes through the sphere
		float dSqrt = sqrt(d);
		float t1 = (-b - dSqrt) / 2 * a;
		float t2 = (-b + dSqrt) / 2 * a;
		list.push_back(new Intersection(p_ray.pos + p_ray.dir * t1));
		list.push_back(new Intersection(p_ray.pos + p_ray.dir * t2));
		//std::cout << "2 intersections" << std::endl;
	}
	return list;
}