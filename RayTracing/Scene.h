#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include "Vector3D.h"
#include "Camera.h"

class Scene
{
public:
	Camera camera;
	//Liste d'objets
	//Liste de lumière

	Scene(void);
};

#endif