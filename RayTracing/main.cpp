#include <iostream>
#include "FreeImage.h"
#include "Scene.h"
//#include <vld.h>

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	
	/*-----Creation de la scene avec la camera-----*/
	/*Creation de la camera et ajout dans la scène*/
	Camera camera(360, 1.5f, 4.0f / 3.0f, 1.0f, 0.1f, 10.0f, Vector3D(0, 0, 0)); //Image en 480 x 360
	//Camera camera(1080, 1.5f, 16.0f / 9.0f, 1.0f, 0.3f, 10.0f, Vector3D(0, 0, 0)); //Image en 1920 x 1080
	Scene scene(camera);
	/*Ou création via une camera par défault*/
	//Scene scene(360, 4.0f/3.0f);
	/*---------------------------------------------*/

	image = FreeImage_Allocate((int)scene.camera.img_width, (int)scene.camera.img_height, 32);
	/** Ajout d'objets dans la scène**/
	//Sphère (de type miroir)
	scene.addObject(new Sphere(
		Vector3D(0.3f, 0.3f,-1.2f),
		.25f,
		Material(Color(41, 128, 185), 0.2, 0.2, 0.1, true)));	
	//Sphère ( de type diffuse)
	scene.addObject(new Sphere(
		Vector3D(0, -0.3,-1),
		.25f, 
		Material(Color(154, 28, 85), 0.2, 0.3, 0.2, false)));
	//Triangle
	scene.addObject(new Triangle(
		Vector3D(-0.5f, -0.5f, -0.7f),
		Vector3D(-0.7f, 0.4f, -1.2f),
		Vector3D(-0.1f, 0.1f, -1.3f),
		Material(Color(230, 126, 34), 0.3f, 0.4f, 0.9f)
		));
	//Sol
	scene.addObject(new Plan(
		Vector3D(0.0f,-scene.camera.cam_height / 2,0.0f),
		Vector3D(0.0f, 1.0f, 0.0f),
		Material(Color(46, 204, 113), 0.2, 0.3, 0.2)
	));	
	//Fond
	scene.addObject(new Plan(
		Vector3D(0.0f, 0.0f, -3.0f),
		Vector3D(0.0f, 0.0f, 1.0f),
		Material(Color(98, 24, 213), 0.2, 0.3, 0.2)
	));
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
	));

	/** Ajout des lumières (blanches) **/
	scene.addLight(new Light(Vector3D(0.2, 0.2, 0), Color(255, 255, 255)));
	scene.addLight(new Light(Vector3D(-0.2, -0.2, 0), Color(255, 255, 255)));


	unsigned int i, j;
	unsigned int width = scene.camera.img_width;
	unsigned int height = scene.camera.img_height;
	Color pixel_color;
	scene.information();  
	//Pour chaques pixels de l'image à générer
	for (i = 0; i < width; i++) 
	{
		for (j = 0; j < height; j++)
		{
			scene.camera.traceRay(i, j);//On trace un rayon pour le pixel de coordonnées (i, j)
			Intersection* intersection = scene.intersection(scene.camera.ray);//On récupère l'intersection la plus proche
			if (intersection)
			{
				pixel_color = scene.getPixelColor(*intersection);//On calcul la couleur (ombre, reflexion, impact lumière sur materiau de Blinn-Phong)
				color.rgbRed = pixel_color.r;
				color.rgbGreen = pixel_color.g;
				color.rgbBlue = pixel_color.b;
			}
			else 
			{
				//Si aucun n'objet n'est traversé par le rayon, le pixel est noir
				color.rgbRed = 0;
				color.rgbGreen = 0;
				color.rgbBlue = 0;
			}
			delete intersection;
			FreeImage_SetPixelColor(image, i, height-j-1, &color);
		}
	}
	//Sauvegarde de l'image au format BMP
	FreeImage_Save(FIF_BMP, image, "out.bmp");
	return EXIT_SUCCESS;
}