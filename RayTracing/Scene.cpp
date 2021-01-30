#include "Scene.h"

Scene::Scene(void)
{
	this->nbObjects = 0;
}

Scene::Scene(float p_img_height, float p_format)
{
	camera = Camera(p_img_height, 1.5, p_format, 1.0, 0.3, 100.0, Vector3D(0, 0, 0));
	std::cout << camera.img_width << std::endl;
	this->nbObjects = 0;
}

Scene::~Scene(void)
{

}


void Scene::addObject(Object* p_object) 
{
	this->objects.push_back(p_object);
	this->nbObjects++;
}
