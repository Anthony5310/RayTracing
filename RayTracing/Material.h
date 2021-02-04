#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include "Vector3D.h"
#include "Color.h"

//Definition d'un materiaux de Blinn-Phong
class Material {
public:
	Color color;
	float kAmbiant;
	float kDiffus;
	float kSpecular;

	Material(void);
	Material(Color p_color, float p_kAmbiant, float p_kDiffus, float p_kSpecular);

};
#endif // !_MATERIAL_H_
