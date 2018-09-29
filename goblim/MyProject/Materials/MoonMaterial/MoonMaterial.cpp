#include "MoonMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


MoonMaterial::MoonMaterial(std::string name) :
	MaterialGL(name, "MoonMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	modelView = vp->uniforms()->getGPUmat4("MV");
	colorSampler = fp->uniforms()->getGPUsampler("colorTex");
	normalSampler = fp->uniforms()->getGPUsampler("normalTex");
	specSampler = fp->uniforms()->getGPUsampler("specTex");

	modelViewF = fp->uniforms()->getGPUmat4("NormalMV");
	modelMatrix = fp->uniforms()->getGPUmat4("modelMatrix");

	modelViewProj = vp->uniforms()->getGPUmat4("MVP");

	normalTex = new GPUTexture2D(ressourceTexPath + "MoonN.png");
	normalSampler->Set(normalTex->getHandle());

	colorTex = new GPUTexture2D(ressourceTexPath + "MoonD.png");
	colorSampler->Set(colorTex->getHandle());

	specTex = new GPUTexture2D(ressourceTexPath + "MoonS.png");
	specSampler->Set(specTex->getHandle());

}

MoonMaterial::~MoonMaterial()
{

}

void MoonMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}

}

void MoonMaterial::update(Node* o, const int elapsedTime)
{
}