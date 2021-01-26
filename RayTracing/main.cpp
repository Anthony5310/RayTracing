#include <iostream>
#include "FreeImage.h"
#include "Vector3D.h"

int main(int argc, char** argv)
{
	Vector3D v1(1, 2, 3);
	v1.display();
	std::cout << v1.norm() << std::endl;

	return EXIT_SUCCESS;
}