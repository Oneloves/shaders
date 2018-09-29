#ifndef _MOONMATERIAL_H
#define _MOONMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class MoonMaterial : public MaterialGL
{
	public:
		MoonMaterial(std::string name);
		~MoonMaterial();
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