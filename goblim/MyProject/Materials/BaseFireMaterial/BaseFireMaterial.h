#ifndef _BASEFIREMATERIAL_H
#define _BASEFIREMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class BaseFireMaterial : public MaterialGL
{
	public:
		BaseFireMaterial(std::string name);
		~BaseFireMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif