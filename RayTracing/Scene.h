#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include "Vector3D.h"

class Scene
{
public:
	float width, height; //Camera size
	float format; //ex: 16:9 | ex: width = format * height

	Scene(void);
	Scene(float p_width, float p_height);
	Scene(float p_height, float p_format);
};

#endif