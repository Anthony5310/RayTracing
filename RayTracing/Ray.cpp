#include "Ray.h"

Ray::Ray(void):
	pos(Vector3D(0,0,0)), dir(Vector3D(1,1,1))
{
}

Ray::Ray(Vector3D p_origin, Vector3D p_dir):
	pos(p_origin), dir(p_dir)
{
}

void Ray::setPos(Vector3D p_pos)
{
	pos = p_pos;
}

void Ray::setDir(Vector3D p_dir)
{
	pos = p_dir;
}

void Ray::display(void) {
	std::cout << "Position : ";
	this->pos.display();
	std::cout << "Direction : ";
	this->dir.display();
}