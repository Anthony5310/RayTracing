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

class Scene
{ 
public:
	Camera camera;
	//Liste d'objets
	unsigned int nbObjects;
	std::vector<Object*> objects;
	std::vector<Intersection*> intersections;
	//Liste de lumière

	Scene(void);
	~Scene(void);
	void addObject(Object* p_object);
};

#endif