#ifndef _ROCKMATERIAL_H
#define _ROCKMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class RockMaterial : public MaterialGL
{
	public:
		RockMaterial(std::string name);
		~RockMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif