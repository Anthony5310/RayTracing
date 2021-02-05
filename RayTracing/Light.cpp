#include "Light.h"

Light::Light():
	Object()
{
	position = Vector3D(0.01,0.01,0);
	color = Vector3D(2.0,2.0,2.0);
}