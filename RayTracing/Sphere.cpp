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
	float lightDist = (p_lights[0]->position - p_intersection.position).norm(); //Distance entre le point d'intersection et la lumière
	/*** ambiant ***/
	Color ambiant = this->material.color * this->material.kAmbiant;

	/*** diffuse ***/
	Vector3D L = (p_lights[0]->position - p_intersection.position).getNormalize();
	//Vecteur normalisé du point d'intersection vers la lumière
	float NL = p_intersection.normal.scalarProduct(L); //N.L
	if (NL < 0)	NL = 0.0f; //max(0, N.L)
	Color diffuse = p_lights[0]->color * NL  * (1 / lightDist*lightDist) * this->material.kDiffus;

	/*** specular ***/
	//Vecteur normalisé du point d'intersection vers le point de la camera
	Vector3D V = (p_ray.pos - p_intersection.position).getNormalize();
	Vector3D H = (V + L).getNormalize();// V+L / ||V+L||
	float NH = p_intersection.normal.scalarProduct(H);// N.H
	NH = pow(NH, 16); //max(0, NH)
	if (NH < 0) NH = 0;
	Color specular = p_lights[0]->color * NH * (1 / lightDist*lightDist) * this->material.kSpecular;
	
	Color totalLight = (ambiant + diffuse + specular);
	return totalLight;
}

Color Sphere::getColor(void)
{
	return material.color;
}

