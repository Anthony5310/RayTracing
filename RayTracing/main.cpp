#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	Scene scene(360, 4.0/3.0);
	image = FreeImage_Allocate((int)scene.camera.img_width, (int)scene.camera.img_height, 32);
	scene.addObject(new Sphere(Vector3D(0, 0,-1), .25f, Color(41, 128, 185)));
	scene.addObject(new Sphere(Vector3D(0.25, 0.25,-1.25), .25f, Color(211, 84, 0)));
	scene.addObject(new Sphere(Vector3D(0, -101,-3), 100.0f, Color(52, 73, 94)));
	scene.addLight(new Light());
	std::cout << scene.camera.img_width << " " << scene.camera.img_height << std::endl;
	unsigned int i, j, k;
	unsigned int width = scene.camera.img_width;
	unsigned int height = scene.camera.img_height;
	Color pixel_color;
	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			scene.camera.traceRay(i, j);
			for (k = 0; k < scene.nbObjects; k++) //foreach objects of the scene
			{
				Intersection* intersection = scene.intersection();
				if (intersection)
				{
					pixel_color = scene.objects[intersection->objectId]->lightImpact(scene.camera.ray, scene.lights, *intersection);
					//pixel_color = scene.objects[intersection->objectId]->getColor();
					color.rgbRed = pixel_color.r;
					color.rgbGreen = pixel_color.g;
					color.rgbBlue = pixel_color.b;
				}
				else 
				{
					color.rgbRed = 110;
					color.rgbGreen = 110;
					color.rgbBlue = 110;
				}
			}
			FreeImage_SetPixelColor(image, width-i-1, height-j-1, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}

/*
	float calculatePhong(Vector sphereCenter, Vector intersection, Vector lightPosition, Vector rayOrigin, Material sphereMaterial) {
	Vector sphereNormal = (intersection - sphereCenter).normalized();
	Vector lightDirection = (lightPosition - intersection).normalized();
	Vector viewDirection = (intersection - rayOrigin).normalized();
	Vector blinnDirection = (lightDirection - viewDirection).normalized();
	float blinnTerm = std::max(blinnDirection.dot(sphereNormal), 0.0f);
	return sphereMaterial.specValue * powf(blinnTerm, sphereMaterial.specPower);
}*/