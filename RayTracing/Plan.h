#ifndef _PLAN_H_
#define _PLAN_H_
#include "PrimitiveObject.h"

class Plan : public PrimitiveObject
{
public:
	float width;
	float height;

	Plan(void);
	Plan(Vector3D p_position, float p_width, float p_height);
};
#endif