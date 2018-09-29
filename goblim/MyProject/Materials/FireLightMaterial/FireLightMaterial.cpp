#include "FireLightMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


FireLightMaterial::FireLightMaterial(std::string name) :
	MaterialGL(name, "FireLightMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = vp->uniforms()->getGPUfloat("TIME");
}

FireLightMaterial::~FireLightMaterial()
{

}

void FireLightMaterial::setColor(glm::vec4 &c)
{

}

void FireLightMaterial::render(Node *o)
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

void FireLightMaterial::update(Node* o, const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
