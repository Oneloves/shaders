#include "BaseFireMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


BaseFireMaterial::BaseFireMaterial(std::string name):
	MaterialGL(name,"BaseFireMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

BaseFireMaterial::~BaseFireMaterial()
{

}

void BaseFireMaterial::setColor(glm::vec4 &c)
{

}

void BaseFireMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void BaseFireMaterial::update(Node* o,const int elapsedTime)
{
}
