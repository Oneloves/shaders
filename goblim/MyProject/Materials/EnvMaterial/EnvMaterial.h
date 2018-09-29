#ifndef _ENVMATERIAL_H
#define _ENVMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include "Blur/Blur.h"
#include <memory.h>

class EnvMaterial : public MaterialGL
{
	public:
		EnvMaterial(std::string name);
		~EnvMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUmat4* matrix;
		GPUfloat* time;
		GPUTexture2D* texture2D;
		GPUsampler* sampler;
		GPUvec3* lightPos;
		GPUTexture2D* colorTex;
		GPUTexture2D* colorTex2;
		GPUsampler *colorSampler;
		GPUsampler *colorSampler2;
};

#endif