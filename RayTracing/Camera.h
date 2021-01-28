#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <iostream>
#include "Vector3D.h"

class Camera
{
	Vector3D pos;
	Vector3D dir;
	float cam_width, cam_height; //Camera size
	float img_width, img_height; //Image size
	float near, far; //minimum and maximum distance  vision
	float format; //ou ratio ex: 16:9 | ex: width = format * height
	float focal;


	Camera(void);
	Camera(float p_img_height, float p_cam_height, float p_format, float p_focal, float p_near, float p_far, Vector3D p_pos);
};
#endif
