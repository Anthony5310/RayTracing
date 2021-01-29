#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	Scene scene;
	scene.addObject(Sphere());
	unsigned int i, j, k;
	for (i = 0; i < scene.camera.img_width; i++) 
	{
		for (j = 0; j < scene.camera.img_height; j++) 
		{
			scene.camera.traceRay(i, j);
			for (k = 0; j < scene.nbObjects; k++) //foreach objects of the scene
			{

			}
		}
	}
	return EXIT_SUCCESS;
}