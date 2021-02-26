#include "Camera.h"

Camera::Camera(void)
{
	position = Vector3D(0, 0, 0);
	direction = Vector3D(0, 0, -1);
	ray = Ray();
	img_height = 360;
	img_width = 480;
	cam_height = 1.5;
	cam_width = 2.0;
	near = 0.3;
	far = 100.0;
	format = 4.0 / 3.0;
	focal = 1.0;
	setUpLeftCorner();
}

Camera::Camera(float p_img_height, float p_cam_height, float p_format, float p_focal, float p_near, float p_far, Vector3D p_position)
{
	position = p_position;
	direction = Vector3D(0, 0, -1);
	ray = Ray();
	img_height = p_img_height;
	img_width = p_format * p_img_height;
	cam_height = p_cam_height;
	cam_width = p_format * p_cam_height;
	near = p_near;
	far = p_far;
	format = p_format;
	focal = p_focal;
	setUpLeftCorner();
}

void Camera::setUpLeftCorner(void) {
	upLeftCorner = this->position - Vector3D(cam_width / 2, -cam_height / 2, focal);
}

void Camera::traceRay(unsigned int i, unsigned int j) {
	Vector3D horizontalDir(this->cam_width, 0, 0);
	Vector3D verticalDir(0, -this->cam_height, 0);
	float u = (float)i / (img_width - 1);
	float v = (float)j / (img_height - 1);
	this->ray.setPos(this->position);
	this->ray.setDir((this->upLeftCorner + (horizontalDir * u) + (verticalDir * v) - this->position).getNormalize());
}
