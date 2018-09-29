#ifndef _SUNLIGHTMATERIAL_H
#define _SUNLIGHTMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class SunLightMaterial : public MaterialGL
{
	public:
		SunLightMaterial(std::string name);
		~SunLightMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif