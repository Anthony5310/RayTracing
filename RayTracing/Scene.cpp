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

Intersection* Scene::intersection(void)
{
	unsigned int i;
	float tMin = 100000.0f;
	float tCurrent;
	int objectId=-1;
	Intersection* intersection = NULL;
	for (i = 0; i < this->nbObjects; i++) {
		tCurrent = this->objects[i]->intersection(camera.ray);
		if (tCurrent > 0 && tCurrent < tMin)
		{
			tMin = tCurrent;
			objectId = i;
		}
	}
	if (objectId >= 0)
	{
		Vector3D posIntersection = camera.ray.pos + camera.ray.dir * tMin;
		Vector3D normale = posIntersection - this->objects[objectId]->position;
		normale.normalize();
		intersection = new Intersection(posIntersection, normale, objectId, tMin);
	}
	return intersection;
}

bool Scene::shadow(Intersection* p_intersection)
{
	Ray secondRay(p_intersection->position+p_intersection->normal*0.01, (this->lights[0]->position - p_intersection->position).getNormalize());
	this->camera.ray = secondRay;
	Intersection* intersection = this->intersection();	
	float d = (this->lights[0]->position - p_intersection->position).norm();
	if (intersection && intersection->t * intersection->t < d * d) {
		return true;
	}
	return false;
}
