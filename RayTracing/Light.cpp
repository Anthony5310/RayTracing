#include "Light.h"

Light::Light():
	Object()
{
	position = Vector3D(0.1,0.1,0);
	color = Vector3D(1.0,1.0,1.0);
	ambiantColor = Vector3D(0.1, 0.0, 0.0);
	diffuseColor = Vector3D(1.0, 0.0, 0.0);
	specularColor = Vector3D(1.0, 1.0, 1.0);
	power = 40.0;
}