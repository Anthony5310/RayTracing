#include "Light.h"

Light::Light():
	Object()
{
	position = Vector3D(0.1,0.1,0);
	color = Color(255,255,255);
}

Light::Light(Vector3D p_position, Color p_color) :
	Object()
{
	position = p_position;
	color = p_color;
}