# RayTracing Anthony BARILLER TC1
Projet d'imagerie numérique via l'implémentation de l'algorithme de ray tracing

1. Fonctionnalités:
1.A. Objets
	- Plan
	- Triangle
	- Sphère
1.B. Matériaux
	- Materiau de Blinn-Phong
	- Objet miroir (nombre de reflexion défini par MAX_REFLECT dans "Scene.h") 
	- Ombres portées

2. Implémentations (main.c):
2.A. Ajout d'objet
	- Plan : scene.addObject(new Plan(<Vector3D> position, <Vector3D> normal, <Material> materiau)
	- Sphère: scene.addObject(new Sphere(<Vector3D> position, <float> rayon, <Material> materiau)
	- Triangle: scene.addObject(new Triangle(<Vector3D> coin1, <Vector3D> coin2, <Vector3D> coin3)
2.B. Création d'un materiau
	- Material(<Color> couleur, <float> coeff_ambiant, <float> coeff_diffus, <float> coeff_speculaire, <bool> miroir=false)
	- Puissance spéculaire (n) modifiable dans lightImpact() dans PrimitiveObject.c
2.C. Ajout d'une lumière
	- scene.addLight(new Light(<Vector3D> position, <Color> lumière)
2.D. Création de la scène
	- Camera(<float> hauteur_image, <float> hauteur_camera, <float> format, <float> distance_focal, <float> plan_near, <float> plan_far, <Vector3D> position)
	- Scene(camera) ou Scene(<float> hauteur_image, <float> format)

