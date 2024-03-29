#ifndef _PRIMITIVE_OBJECT_H_
#define _PRIMITIVE_OBJECT_H_
#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Object.h"
#include "Ray.h"
#include "Color.h"
#include "Light.h"
#include "Material.h"

class PrimitiveObject : public Object
{
public:
	Material material;
	
	PrimitiveObject();
	~PrimitiveObject();
	virtual Intersection* intersection(Ray& p_ray) = 0;
	Color lightImpact(Ray& p_ray, std::vector<Light*> p_lights, Intersection& p_intersection);
	virtual Color getColor(void)=0;
};
#endif