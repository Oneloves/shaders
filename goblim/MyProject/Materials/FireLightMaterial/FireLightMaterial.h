#ifndef _FIRELIGHTMATERIAL_H
#define _FIRELIGHTMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class FireLightMaterial : public MaterialGL
{
	public:
		FireLightMaterial(std::string name);
		~FireLightMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif