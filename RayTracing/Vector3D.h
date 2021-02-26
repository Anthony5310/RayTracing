#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_
#include <iostream>
#include <math.h>
#include "Color.h"

class Vector3D 
{
public:
	float x, y, z;

	Vector3D(void);
	Vector3D(float p_x, float p_y, float p_z);
	void display(void);
	float norm(void);
	void normalize(void);
	Vector3D getNormalize(void);
	float scalarProduct(Vector3D p_vector);
	float scalarProduct(float p_scalar);
	Vector3D operator+ (Vector3D p_vector);
	Vector3D operator+ (float p_scalar);
	Vector3D operator- (Vector3D p_vector);
	Vector3D operator/ (float p_scalar);
	//Produit scalaire
	Vector3D operator* (Vector3D p_vector);
	Vector3D operator* (float p_scalar);
	Vector3D operator* (Color p_color);
	//Produit vectoriel
	Vector3D operator^ (Vector3D p_vector);
	//Vecteur reflected regarding normal
	Vector3D reflect(Vector3D p_normal);
	Color toColor(void);
};

#endif