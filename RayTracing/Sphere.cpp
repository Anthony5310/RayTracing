#include "Sphere.h"

Sphere::Sphere(void):
	PrimitiveObject()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	radius = 1.0f;
	material = Material(); //Color white by default
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

float Sphere::intersection(Ray& p_ray)
{
	Vector3D dist = p_ray.pos - this->position;
	//Calcul of discriminant (d), d = b²-4ac
	//float a = p_ray.dir.scalarProduct(p_ray.dir); //Scalar product of ray direction vector (dir) -> dir.dir or 
	float a = 1;
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
	return t;
}

Color Sphere::lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection)
{
	float lightDist = (p_lights[0]->position - p_intersection.position).norm();
	//ambiant
	Vector3D ambiant = p_lights[0]->color * 0.2;

	//diffuse
	Vector3D L = p_lights[0]->position - p_intersection.position;
	L.normalize();
	float Id = p_intersection.normal.scalarProduct(L);
	if (Id < 0) {
		Id = 0.0f;
	}
	Vector3D diffuse = p_lights[0]->color * Id;

	//specular
	/*Vector3D V = p_intersection.position - p_ray.pos;
	V.normalize();
	Vector3D H = (V + L).getNormalize();
	float Is = p_intersection.normal.scalarProduct(H);
	if (Is < 0) {
		Is = 0.0f;
	}
	else {
		Is = pow(Is, 32);
	}
	Vector3D specular = p_lights[0]->color *  Is;*/
	
	Vector3D totalLight = (ambiant + diffuse) * this->material.color;
	return Color((char)totalLight.x, (char)totalLight.y, (char)totalLight.z);
}

Color Sphere::getColor(void)
{
	return material.color;
}

