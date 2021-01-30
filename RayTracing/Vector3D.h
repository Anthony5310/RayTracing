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
	float scalarProduct(Vector3D p_vector);
	float scalarProduct(float p_scalar);
	Vector3D operator+ (Vector3D p_vector);
	Vector3D operator- (Vector3D p_vector);
	//Produit scalaire
	Vector3D operator* (Vector3D p_vector);
	Vector3D operator* (float p_scalar);
	Vector3D operator* (Color p_color);
	//Produit vectoriel
	Vector3D operator^ (Vector3D p_vector);
};

#endif