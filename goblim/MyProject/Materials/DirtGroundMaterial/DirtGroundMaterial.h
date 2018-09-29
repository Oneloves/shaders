#ifndef _DIRTGRIUNDMATERIAL_H
#define _DIRTGRIUNDMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class DirtGroundMaterial : public MaterialGL
{
	public:
		DirtGroundMaterial(std::string name);
		~DirtGroundMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;

};

#endif