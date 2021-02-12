#include "Plan.h"

Plan::Plan(void):
	PrimitiveObject()
{
	width = 1.0;
	height = 1.0;
}

Plan::Plan(Vector3D p_position, float p_width, float p_height) :
	PrimitiveObject(), width(p_width), height(p_height)
{
	position = p_position;
}