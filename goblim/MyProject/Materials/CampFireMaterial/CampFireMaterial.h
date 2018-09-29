#ifndef _CAMPFIREMATERIAL_H
#define _CAMPFIREMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class CampFireMaterial : public MaterialGL
{
	public:
		CampFireMaterial(std::string name);
		~CampFireMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif