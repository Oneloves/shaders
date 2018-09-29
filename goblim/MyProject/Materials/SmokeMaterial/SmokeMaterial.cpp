#include "SmokeMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


SmokeMaterial::SmokeMaterial(std::string name) :
	MaterialGL(name, "SmokeMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
	sampler = fp->uniforms()->getGPUsampler("SAMPLER");
	texture2D = new GPUTexture2D(ressourceTexPath + "Sun2.jpg");

	sampler->Set(texture2D->getHandle());
}

SmokeMaterial::~SmokeMaterial()
{

}

void SmokeMaterial::setColor(glm::vec4 &c)
{

}

void SmokeMaterial::render(Node *o)
{
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
	glDisable(GL_BLEND);

}

void SmokeMaterial::update(Node* o, const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
