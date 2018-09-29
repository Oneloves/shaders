#include "SunLightMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


SunLightMaterial::SunLightMaterial(std::string name) :
	MaterialGL(name, "SunLightMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
}

SunLightMaterial::~SunLightMaterial()
{

}

void SunLightMaterial::setColor(glm::vec4 &c)
{

}

void SunLightMaterial::render(Node *o)
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

void SunLightMaterial::update(Node* o, const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
