#include "Scene.h"

Scene::Scene(void)
{
	this->nbObjects = 0;
	this->nbLights = 0;
}

Scene::Scene(float p_img_height, float p_format)
{
	camera = Camera(p_img_height, 1.5, p_format, 1.0, 0.3, 100.0, Vector3D(0, 0, 0));
	std::cout << camera.img_width << std::endl;
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

	unsigned int nbIntersections = intersections.size();
	for (i = 0; i < nbIntersections; i++) {
		delete this->intersections[i];
	}
}


void Scene::addObject(Object* p_object) 
{
	this->objects.push_back(p_object);
	this->nbObjects++;
}

void Scene::addLight(Light* p_light)
{
	this->lights.push_back(p_light);
	this->nbLights++;
}
