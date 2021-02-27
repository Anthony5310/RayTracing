#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_
#include <iostream>
#include "Vector3D.h"

class Intersection 
{
public:
	Vector3D position; //Position de l'intersection
	Vector3D normal; //Vecteur normal à l'objet au point d'intersection
	int objectId; //id de l'objet traité
	float t; //valeur de t tel que: position = ray.position + t x ray.direction 

	Intersection(void);
	Intersection(Vector3D p_position, Vector3D p_normal, int p_objectId, float p_t);
};

#endif
