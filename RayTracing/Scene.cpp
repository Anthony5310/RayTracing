#include "Scene.h"

Scene::Scene(void):
	width(1920), height(1080), format(16/9)
{
}

Scene::Scene(float p_width, float p_height):
	height(p_height), width(p_width), format(p_width / p_height)
{
}

Scene::Scene(float p_height, float p_format) :
	height(p_height), width(p_height* p_format), format(p_format)
{
}