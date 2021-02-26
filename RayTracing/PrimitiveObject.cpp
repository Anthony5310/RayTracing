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
	unsigned int i;
	unsigned int nbLights = p_lights.size();
	/*** ambiant ***/
	Color ambiant = this->material.color;
	Color diffuse = Color(0, 0, 0);
	Color specular = Color(0, 0, 0);
	for (i = 0; i < nbLights; i++) {
		float lightDist = (p_lights[i]->position - p_intersection.position).norm(); //Distance entre le point d'intersection et la lumière

		/*** diffuse ***/
		Vector3D L = (p_lights[i]->position - p_intersection.position).getNormalize();
		//Vecteur normalisé du point d'intersection vers la lumière
		float NL = p_intersection.normal.scalarProduct(L); //N.L
		if (NL < 0)	NL = 0.0f; //max(0, N.L)
		diffuse = diffuse + (p_lights[i]->color * NL * (1 / lightDist * lightDist));

		/*** specular ***/
		//Vecteur normalisé du point d'intersection vers le point de la camera
		Vector3D V = (p_ray.pos - p_intersection.position).getNormalize();
		Vector3D H = (V + L).getNormalize();// V+L / ||V+L||
		float NH = p_intersection.normal.scalarProduct(H);// N.H
		NH = pow(NH, 16); //max(0, NH)
		if (NH < 0) NH = 0;
		specular = specular + (p_lights[i]->color * NH * (1 / lightDist * lightDist));
	}

	Color pixelColor = (ambiant * this->material.kAmbiant + diffuse * this->material.kDiffus + specular * this->material.kSpecular);
	return pixelColor;
}

Color PrimitiveObject::getColor(void)
{
	return Color(0, 0, 0);
}
