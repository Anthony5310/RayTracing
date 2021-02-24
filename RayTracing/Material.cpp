#include "Material.h"

Material::Material(void)
{
	color = Color();
	kAmbiant = 1.0f;
	kDiffus = 1.0f;
	kSpecular = 1.0f;
	mirror = false;
}

Material::Material(Color p_color, float p_kAmbiant, float p_kDiffus, float p_kSpecular, bool p_mirror):
	color(p_color), kAmbiant(p_kAmbiant), kDiffus(p_kDiffus), kSpecular(p_kSpecular), mirror(p_mirror)
{
}