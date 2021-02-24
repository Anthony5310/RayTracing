#include "PrimitiveObject.h"

PrimitiveObject::PrimitiveObject(void) :
	Object()
{
	material = Material(); //Color white by default
}

PrimitiveObject::~PrimitiveObject(void)
{
	material = Material(); //Color white by default
}

Intersection* PrimitiveObject::intersection(Ray& p_ray)
{
	return NULL;
}

Color PrimitiveObject::lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection)
{
	float lightDist = (p_lights[0]->position - p_intersection.position).norm(); //Distance entre le point d'intersection et la lumière
	/*** ambiant ***/
	Color ambiant = this->material.color * this->material.kAmbiant;

	/*** diffuse ***/
	Vector3D L = (p_lights[0]->position - p_intersection.position).getNormalize();
	//Vecteur normalisé du point d'intersection vers la lumière
	float NL = p_intersection.normal.scalarProduct(L); //N.L
	if (NL < 0)	NL = 0.0f; //max(0, N.L)
	Color diffuse = p_lights[0]->color * NL * (1 / lightDist * lightDist) * this->material.kDiffus;

	/*** specular ***/
	//Vecteur normalisé du point d'intersection vers le point de la camera
	Vector3D V = (p_ray.pos - p_intersection.position).getNormalize();
	Vector3D H = (V + L).getNormalize();// V+L / ||V+L||
	float NH = p_intersection.normal.scalarProduct(H);// N.H
	NH = pow(NH, 16); //max(0, NH)
	if (NH < 0) NH = 0;
	Color specular = p_lights[0]->color * NH * (1 / lightDist * lightDist) * this->material.kSpecular;

	Color pixelColor = (ambiant + diffuse + specular);
	return pixelColor;
}

Color PrimitiveObject::getColor(void)
{
	return Color(0, 0, 0);
}
