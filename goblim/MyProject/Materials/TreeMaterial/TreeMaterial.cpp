#include "TreeMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


TreeMaterial::TreeMaterial(std::string name):
	MaterialGL(name,"TreeMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

TreeMaterial::~TreeMaterial()
{

}

void TreeMaterial::setColor(glm::vec4 &c)
{

}

void TreeMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void TreeMaterial::update(Node* o,const int elapsedTime)
{
}
