#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	Vector3D v1(1, 2, 3);
	Vector3D v2(-1, 8, 9);
	v1.display();
	v1.normalize();
	v1.display();
	std::cout << v1.norm() << std::endl;
	Intersection::touch();

	return EXIT_SUCCESS;
}