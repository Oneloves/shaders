#ifndef _GLASSMATERIAL_H
#define _GLASSMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class GlassMaterial : public MaterialGL
{
	public:
		GlassMaterial(std::string name);
		~GlassMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif