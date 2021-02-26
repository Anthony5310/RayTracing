#include "Triangle.h"

Triangle::Triangle(void):
	PrimitiveObject()
{
	p0 = Vector3D(0, 0, 0);
	p1 = Vector3D(0, 1, 0);
	p2 = Vector3D(1, 0, 0);
}

Triangle::Triangle(Vector3D p_p0, Vector3D p_p1, Vector3D p_p2, Material p_material):
	PrimitiveObject()
{
	p0 = p_p0;
	p1 = p_p1;
	p2 = p_p2;
	material = p_material;
}

Intersection* Triangle::intersection(Ray& p_ray) {
	Vector3D v0 = (this->p1 - this->p0).getNormalize();
	Vector3D v1 = (this->p2 - this->p0).getNormalize();
	Vector3D normal = v0 ^ v1;
	float d = normal.scalarProduct(this->p0);
	float t;
	float ndotrd = p_ray.dir.scalarProduct(normal);
	if (fabs(ndotrd) < 0.0001) return NULL;
	t = (p_ray.pos.scalarProduct(normal) + d) / ndotrd;
	if (t < 0.0f) return NULL;
	Vector3D p = p_ray.pos + p_ray.dir * t;
	//On verifie que l'intersection se trouve à l'interieur des limites du triangle
	Vector3D limit = v0.getNormalize();
	Vector3D vPiP = p - this->p0; //Vecteur du point pi (pour i de 0 à 2, p0 p1 p2) au point d'intersection p
	Vector3D side; //Indicateur de position du point d'intersection dans le triangle (interieur ou exterieur)
	side = limit ^ vPiP;
	if (side.scalarProduct(normal) < 0) return NULL;

	limit = (this->p2 - this->p1).getNormalize();
	vPiP = p - this->p1;
	side = limit ^ vPiP;
	if (side.scalarProduct(normal) < 0) return NULL;

 	limit = (this->p0 - this->p2).getNormalize();
	vPiP = p - this->p2;
	side = limit ^ vPiP;
	if (side.scalarProduct(normal) < 0) return NULL;

	//Si nous sommes ici c'est que le point d'intersection se trouve bien dans le triangle
	//On peut donc créer un objet intersection
	Intersection* newIntersection = new Intersection(p, normal, 0, t);
	return newIntersection;
}

Color Triangle::getColor(void)
{
	return material.color;
}