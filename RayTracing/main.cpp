#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	Scene scene;
	image = FreeImage_Allocate((int)scene.camera.img_width, (int)scene.camera.img_height, 32);
	scene.addObject(new Sphere(Vector3D(0,0,-5), 1.0f, Color()));
	std::cout << scene.camera.img_width << " " << scene.camera.img_height << std::endl;
	unsigned int i, j, k;
	for (i = 0; i < scene.camera.img_width; i++) 
	{
		for (j = 0; j < 1; j++) 
		{
			scene.camera.traceRay(i, j);
			for (k = 0; k < scene.nbObjects; k++) //foreach objects of the scene
			{
				if (scene.objects[k]->intersections(scene.camera.ray).empty())
				{
					color.rgbRed = 0;
					color.rgbGreen = 0;
					color.rgbBlue = 255;
					//std::cout << "Intersection : (" << i << ", " << j << ")" << std::endl;
				}
				else {
					color.rgbRed = 0;
					color.rgbGreen = 0;
					color.rgbBlue = 0;
				}
			}
			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}
	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}