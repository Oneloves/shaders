#ifndef _TREESHADOWMATERIAL_H
#define _TREESHADOWMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class TreeShadowMaterial : public MaterialGL
{
	public:
		TreeShadowMaterial(std::string name);
		~TreeShadowMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif