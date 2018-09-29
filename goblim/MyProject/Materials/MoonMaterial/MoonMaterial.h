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

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj, *modelView, *modelViewF, *modelMatrix;
		GPUTexture2D* colorTex;
		GPUTexture2D* normalTex;
		GPUTexture2D* specTex;
		GPUsampler *colorSampler, *normalSampler, *specSampler;
};

#endif