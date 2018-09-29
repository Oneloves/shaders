#ifndef _SPACEMATERIAL_H
#define _SPACEMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class SpaceMaterial : public MaterialGL
{
	public:
		SpaceMaterial(std::string name);
		~SpaceMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);

		GPUmat4* modelViewProj;
		GPUfloat* time;
		GPUTexture2D* texture2D;
		GPUsampler* sampler;
};

#endif