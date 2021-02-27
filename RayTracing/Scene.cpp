#include "Scene.h"

Scene::Scene(void)
{
	this->nbObjects = 0;
	this->nbLights = 0;
}

Scene::Scene(float p_img_height, float p_format)
{
	camera = Camera(p_img_height, 1.5f, p_format, 1.0f, 0.3f, 10.0f, Vector3D(0, 0, 0));
	this->nbObjects = 0;
	this->nbLights = 0;
}

Scene::Scene(Camera p_camera)
{
	camera = p_camera;
	this->nbObjects = 0;
	this->nbLights = 0;
}

Scene::~Scene(void)
{
	unsigned int i;
	for (i = 0; i < this->nbObjects; i++) {
		delete this->objects[i];
	}

	for (i = 0; i < this->nbLights; i++) {
		delete this->lights[i];
	}
}

void Scene::information(void)
{
	std::cout << "Dimensions: " << this->camera.img_width << "x" << this->camera.img_height << std::endl;
	std::cout << "Nb objets :  " << this->nbObjects << std::endl;
	std::cout << "Nb lights :  " << this->nbLights << std::endl;
}

void Scene::addObject(PrimitiveObject* p_object)
{
	this->objects.push_back(p_object);
	this->nbObjects++;
}

void Scene::addLight(Light* p_light)
{
	this->lights.push_back(p_light);
	this->nbLights++;
}

Intersection* Scene::intersection(Ray& p_ray)
{
	unsigned int i;
	float tMin = 100000.0f;
	Intersection* currentIntersection = NULL;
	Intersection* intersection = NULL;
	//On récupere l'intersection ayant le plus petit t positif
	for (i = 0; i < this->nbObjects; i++) {
		currentIntersection = this->objects[i]->intersection(p_ray);
		if (currentIntersection && currentIntersection->t >= 0 && currentIntersection->t < tMin && currentIntersection->t <= this->camera.far)
		{
			tMin = currentIntersection->t;
			currentIntersection->objectId = i; //On récupère l'ID de l'objet le plus proche
			delete intersection;
			intersection = currentIntersection;
		}
		else {
			delete currentIntersection;
		}
	}
	return intersection;
}

std::vector<Light*> Scene::shadow(Intersection& p_intersection)
{
	std::vector<Light*> listImpactLights; //Liste des lumières ayant un impact sur l'objet traité
	unsigned int i;
	for (i = 0; i < this->nbLights; i++) {
		//Tracé d'un rayon secondaire entre le point d'intersection et la lumiere i
		Ray secondRay(p_intersection.position + p_intersection.normal * 0.001,
			(this->lights[i]->position - p_intersection.position).getNormalize());
		Intersection* intersection = this->intersection(secondRay);
		float d = (this->lights[i]->position - p_intersection.position).norm();
		/*Si, il n'y a pas d'intersection ou une intersection avec un objet dont la distance est
		supérieur à la distance entre l'objet traité et la lumière i*/
		if (!intersection || intersection->t * intersection->t >= d * d) {
			listImpactLights.push_back(this->lights[i]); //On ajoute la lumière i à la liste des lumières ayant un impact sur l'objet
		}
		delete intersection;
	}
	return listImpactLights;
}

Color Scene::getPixelColor(Intersection& p_intersection, int nbReflect) {
	
	if (this->objects[p_intersection.objectId]->material.mirror) { //Si l'objet est un mirroir
		Color pixel;
		//Si le nombre de reflect maximum a été atteint sans atteindre d'object diffus, on renvoie la couleur noir
		if (nbReflect >= MAX_REFLECT)
			return Color(0, 0, 0);
		//Calcul du rayon réfléchi
		Vector3D mirrorDir = this->camera.ray.dir.reflect(p_intersection.normal);
		//Création d'un rayon secondaire
		Ray mirrorRay(p_intersection.position + p_intersection.normal * 0.001, mirrorDir);
		Intersection* intersection = this->intersection(mirrorRay);
		if (intersection) {
			//Récursivité avec incrémentation du nombre de reflection éffectuée 
			pixel = getPixelColor(*intersection, nbReflect+=1);
			delete intersection;
		}
		else {
			pixel = Color(0, 0, 0);
		}
		return pixel;
	}
	else { //Sinon (objet diffus)
		std::vector<Light*> listLightsImpact;
		listLightsImpact = this->shadow(p_intersection);
		if (listLightsImpact.size() == 0) {
			return Color(0, 0, 0);
		}
		return this->objects[p_intersection.objectId]->lightImpact(this->camera.ray, listLightsImpact, p_intersection);
	}
}