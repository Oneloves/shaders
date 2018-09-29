#include "RockMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


RockMaterial::RockMaterial(std::string name):
	MaterialGL(name,"RockMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
}

RockMaterial::~RockMaterial()
{

}

void RockMaterial::setColor(glm::vec4 &c)
{

}

void RockMaterial::render(Node *o)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);

	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void RockMaterial::update(Node* o,const int elapsedTime)
{
}
