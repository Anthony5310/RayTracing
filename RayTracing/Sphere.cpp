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
	//Calcul of discriminant (d), d = b²-4ac
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
		float t;
		if (t1 > 0) {
			t = t1;
		}
		else {
			t = t2;
		}
		if (t > 0) 
		{
			intersection = new Intersection();
			intersection->position = p_ray.pos + p_ray.dir * t;
			intersection->normal = (intersection->position - this->position);
		}
	}
	return intersection;
}

Color Sphere::lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection)
{
	//ambiant
	Vector3D ambiant = p_lights[0]->color * 0.1;

	//diffuse
	Vector3D L = p_lights[0]->position - p_intersection.position;
	L.normalize();
	float Id = std::max(p_intersection.normal.scalarProduct(L), 0.0f);
	Vector3D diffuse = p_lights[0]->color * Id;

	//specular
	Vector3D V = p_intersection.position - p_ray.pos;
	V.normalize();
	Vector3D R = p_intersection.normal * 2.0f * p_intersection.normal.scalarProduct(L) - L;
	float spec = pow(std::max(V.scalarProduct(R), 0.0f), 32);
	Vector3D specular = p_lights[0]->color * (0.5 * spec);

	Vector3D totalLight = (ambiant + diffuse + specular) * this->color;
	return Color((char)totalLight.x, (char)totalLight.y, (char)totalLight.z);
}

Color Sphere::getColor(void)
{
	return color;
}

