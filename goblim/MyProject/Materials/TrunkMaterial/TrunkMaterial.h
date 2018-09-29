#ifndef _TRUNKMATERIAL_H
#define _TRUNKMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class TrunkMaterial : public MaterialGL
{
	public:
		TrunkMaterial(std::string name);
		~TrunkMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif