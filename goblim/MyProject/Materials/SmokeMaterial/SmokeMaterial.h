#ifndef _SMOKEMATERIAL_H
#define _SMOKEMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class SmokeMaterial : public MaterialGL
{
	public:
		SmokeMaterial(std::string name);
		~SmokeMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
		GPUTexture2D* texture2D;
		GPUsampler* sampler;
		GPUvec3* lightPos;
};

#endif