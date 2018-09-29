#ifndef _SUNMATERIAL_H
#define _SUNMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class SunMaterial : public MaterialGL
{
	public:
		SunMaterial(std::string name);
		~SunMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;

};

#endif