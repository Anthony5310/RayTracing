#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Color.h"
#include "Object.h"
#include "PrimitiveObject.h"
#include "Light.h"

class Scene
{ 
public:
	Camera camera;
	//Liste d'objets
	unsigned int nbObjects;
	unsigned int nbLights;
	std::vector<PrimitiveObject*> objects;
	std::vector<Light*> lights;
	//Liste de lumière

	Scene(void);
	Scene(float p_img_height, float p_format);
	~Scene(void);
	void addObject(PrimitiveObject* p_object);
	void addLight(Light* p_light);
	Intersection* intersection(void);
	bool shadow(Intersection* p_intersection);
};

#endif