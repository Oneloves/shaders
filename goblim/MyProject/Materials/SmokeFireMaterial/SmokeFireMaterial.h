#ifndef _SMOKEFIREMATERIAL_H
#define _SMOKEFIREMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class SmokeFireMaterial : public MaterialGL
{
	public:
		SmokeFireMaterial(std::string name);
		~SmokeFireMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
};

#endif