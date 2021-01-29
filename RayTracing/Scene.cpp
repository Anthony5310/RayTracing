#include "Scene.h"

Scene::Scene(void)
{
	this->nbObjects = 0;
}

void Scene::addObject(Object p_object) 
{
	this->objects.push_back(p_object);
	this->nbObjects++;
}
