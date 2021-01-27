#include "Camera.h"

Camera::Camera(void):
	height(360), width(480), format(4/3)
{
}

Camera::Camera(float p_width, float p_height, float p_focal, Vector3D p_origin) :
	height(p_height), width(p_width), format(p_width/p_height), focal(p_focal), origin(p_origin)
{
}

Camera::Camera(float p_height, float p_format, float p_focal, Vector3D p_origin):
	height(p_height), width(p_height * p_format), format(p_format), focal(p_focal), origin(p_origin)
{
}