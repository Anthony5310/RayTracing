#include "Light.h"

Light::Light():
	Object()
{
	position = Vector3D(0.1,0.1,0);
	color = Color(255,255,255);
}