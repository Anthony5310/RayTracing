#include "Scene.h"

Scene::Scene(void)
{
	this->nbObjects = 0;
	this->nbLights = 0;
}

Scene::Scene(float p_img_height, float p_format)
{
	camera = Camera(p_img_height, 1.5, p_format, 1.0, 0.3, 100.0, Vector3D(0, 0, 0));
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
	std::cout << "Dimension: " << this->camera.img_height << "x" << this->camera.img_width << std::endl;
	std::cout << "Nb objets: " << this->nbObjects << std::endl;
	std::cout << "Nb lights: " << this->nbLights << std::endl;
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
	for (i = 0; i < this->nbObjects; i++) {
		currentIntersection = this->objects[i]->intersection(p_ray);
		if (currentIntersection && currentIntersection->t >= 0 && currentIntersection->t < tMin)
		{
			tMin = currentIntersection->t;
			currentIntersection->objectId = i;
			intersection = currentIntersection;
		}
	}
	return intersection;
}

bool Scene::shadow(Intersection* p_intersection)
{
	bool isShadow = false;
	Ray secondRay(p_intersection->position+p_intersection->normal*0.1, 
		(this->lights[0]->position - p_intersection->position).getNormalize());
	Intersection* intersection = this->intersection(secondRay);	
	float d = (this->lights[0]->position - p_intersection->position).norm();
	if (intersection && intersection->t * intersection->t < d * d) {
		isShadow = true;
	}
	delete intersection;
	return isShadow;
}
