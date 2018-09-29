#include "TrunkMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


TrunkMaterial::TrunkMaterial(std::string name):
	MaterialGL(name,"TrunkMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

TrunkMaterial::~TrunkMaterial()
{

}

void TrunkMaterial::setColor(glm::vec4 &c)
{

}

void TrunkMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void TrunkMaterial::update(Node* o,const int elapsedTime)
{
}
