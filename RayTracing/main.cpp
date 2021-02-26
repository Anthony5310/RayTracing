#include <iostream>
#include "FreeImage.h"
#include "Scene.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	Scene scene(360, 4.0/3.0);
	//Scene scene(1080, 16.0/9.0);
	image = FreeImage_Allocate((int)scene.camera.img_width, (int)scene.camera.img_height, 32);
	/*scene.addObject(new Sphere(
		Vector3D(0, 0.3,-1),
		.25f,
		Material(Color(41, 128, 185), 0.2, 0.2, 0.1, false)));

	scene.addObject(new Sphere(
		Vector3D(0, -0.3,-1),
		.25f, 
		Material(Color(154, 28, 85), 0.2, 0.3, 0.2, false)));*/
	
	//Sol
	scene.addObject(new Plan(
		Vector3D(0.0f,-scene.camera.cam_height / 2,0.0f),
		Vector3D(0.0f, 1.0f, 0.0f),
		Material(Color(46, 204, 113), 0.2, 0.3, 0.2)
	));
	/*
	//Plafond
	scene.addObject(new Plan(
		Vector3D(0.0f, scene.camera.cam_height/2, 0.0f),
		Vector3D(0.0f, -1.0f, 0.0f),
		Material(Color(52, 73, 94), 0.2, 0.3, 0.2)
	));
	//Mur Gauche
	scene.addObject(new Plan(
		Vector3D(-scene.camera.cam_width / 2, 0.0f, 0.0f),
		Vector3D(1.0f, 0.0f, 0.0f),
		Material(Color(98, 52, 19), 0.2, 0.3, 0.2)
	));
	//Mur Droite
	scene.addObject(new Plan(
		Vector3D(scene.camera.cam_width / 2, 0.0f, 0.0f),
		Vector3D(-1.0f, 0.0f, 0.0f),
		Material(Color(52, 152, 219), 0.2, 0.3, 0.2)
	));*/

	scene.addLight(new Light(Vector3D(0.1, 0.1, 0), Color(255, 255, 255)));


	unsigned int i, j, k;
	unsigned int width = scene.camera.img_width;
	unsigned int height = scene.camera.img_height;
	Color pixel_color;
	scene.information();  
	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			scene.camera.traceRay(i, j);
			Intersection* intersection = scene.intersection(scene.camera.ray);
			if (intersection)
			{
				if (scene.shadow(intersection)) 
				{
					pixel_color = Color(0, 0, 0);//Black
				}
				else
				{
					pixel_color = scene.getPixelColor(*intersection);
				}
				color.rgbRed = pixel_color.r;
				color.rgbGreen = pixel_color.g;
				color.rgbBlue = pixel_color.b;
			}
			else 
			{
				color.rgbRed = 0;
				color.rgbGreen = 0;
				color.rgbBlue = 0;
			}
			delete intersection;
			FreeImage_SetPixelColor(image, i, height-j-1, &color);
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