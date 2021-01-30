#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	Scene scene(1080, 16.0/9.0);
	image = FreeImage_Allocate((int)scene.camera.img_width, (int)scene.camera.img_height, 32);
	scene.addObject(new Sphere(Vector3D(0, 0,-2), 1.0f, Color()));
	std::cout << scene.camera.img_width << " " << scene.camera.img_height << std::endl;
	unsigned int i, j, k;
	unsigned int width = scene.camera.img_width;
	unsigned int height = scene.camera.img_height;
	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			scene.camera.traceRay(i, j);
			for (k = 0; k < scene.nbObjects; k++) //foreach objects of the scene
			{
				if (!scene.objects[k]->intersections(scene.camera.ray).empty())
				{
					color.rgbRed = 255;
					color.rgbGreen = 255;
					color.rgbBlue = 255;
					//std::cout << "Intersection : (" << i << ", " << j << ")" << std::endl;
				}
				else {
					color.rgbRed = 0;
					color.rgbGreen = 0;
					color.rgbBlue = 0;
				}
			}
			FreeImage_SetPixelColor(image, width-i-1, height-j-1, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}