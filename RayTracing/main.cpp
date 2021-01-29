#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	Scene scene;
	scene.addObject(new Sphere());
	scene.camera.traceRay(0, 0);
	Intersection::touch(scene.camera.ray, scene.objects[0]);
	/*unsigned int i, j, k;
	for (i = 0; i < scene.camera.img_width; i++) 
	{
		for (j = 0; j < scene.camera.img_height; j++) 
		{
			scene.camera.traceRay(i, j);
			for (k = 0; k < scene.nbObjects; k++) //foreach objects of the scene
			{
				if (Intersection::touch(scene.camera.ray, scene.objects[k])) 
				{
					//TODO: Intersection
				}
			}
		}
	}*/
	return EXIT_SUCCESS;
}