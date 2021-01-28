#include "Camera.h"

Camera::Camera(void):
	pos(Vector3D(0,0,0)), dir(Vector3D(0,0,-1)), 
	img_height(360), img_width(480), 
	cam_height(1.5), cam_width(2), 
	format(4/3), focal(1), near(0.3), far(100.0)
{
}

Camera::Camera(float p_img_height, float p_cam_height, float p_format, float p_focal, float p_near, float p_far, Vector3D p_pos) :
	pos(p_pos), dir(Vector3D(0, 0, -1)),
	img_height(p_img_height), img_width(p_img_height * p_format), 
	cam_height(p_cam_height), cam_width(p_cam_height* p_format),
	format(p_format), focal(p_focal), near(p_near), far(p_far)
{
}