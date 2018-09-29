#include "TreeShadowMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


TreeShadowMaterial::TreeShadowMaterial(std::string name):
	MaterialGL(name,"TreeShadowMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

TreeShadowMaterial::~TreeShadowMaterial()
{

}

void TreeShadowMaterial::setColor(glm::vec4 &c)
{

}

void TreeShadowMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void TreeShadowMaterial::update(Node* o,const int elapsedTime)
{
}
