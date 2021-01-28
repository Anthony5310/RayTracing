#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include "Vector3D.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Color.h"

class Scene
{
public:
	Camera camera;
	//Liste d'objets
	//Liste de lumière

	Scene(void);
};

#endif