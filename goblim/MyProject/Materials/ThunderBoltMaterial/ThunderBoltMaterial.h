#ifndef _THUNDERBOLTMATERIAL_H
#define _THUNDERBOLTMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class ThunderBoltMaterial : public MaterialGL
{
	public:
		ThunderBoltMaterial(std::string name);
		~ThunderBoltMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif