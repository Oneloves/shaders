#include "CampFireMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


CampFireMaterial::CampFireMaterial(std::string name):
	MaterialGL(name,"CampFireMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = vp->uniforms()->getGPUfloat("TIME");
}

CampFireMaterial::~CampFireMaterial()
{

}

void CampFireMaterial::setColor(glm::vec4 &c)
{

}

void CampFireMaterial::render(Node *o)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);

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

void CampFireMaterial::update(Node* o,const int elapsedTime)
{
}
