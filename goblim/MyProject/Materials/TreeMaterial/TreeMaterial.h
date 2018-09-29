#ifndef _TREEMATERIAL_H
#define _TREEMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class TreeMaterial : public MaterialGL
{
	public:
		TreeMaterial(std::string name);
		~TreeMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif