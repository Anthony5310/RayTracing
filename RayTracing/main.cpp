#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	Camera camera;
	unsigned int i, j;
	for (i = 0; i < camera.img_width; i++) {
		for (j = 0; j < camera.img_height; j++) {
			camera.traceRay(i, j);
			if (!j)
				camera.ray.display();
		}
	}
	return EXIT_SUCCESS;
}