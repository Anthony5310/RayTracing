#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <iostream>
#include "Vector3D.h"

class Camera
{
	Vector3D origin;
	float width, height; //Camera size
	float format; //ex: 16:9 | ex: width = format * height
	float focal;


	Camera(void);
	Camera(float p_width, float p_height, float p_focal, Vector3D p_origin);
	Camera(float p_height, float p_format, float p_focal, Vector3D p_origin);
};
#endif
