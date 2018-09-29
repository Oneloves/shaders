#include "SpaceShipMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


SpaceShipMaterial::SpaceShipMaterial(std::string name):
	MaterialGL(name,"SpaceShipMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

SpaceShipMaterial::~SpaceShipMaterial()
{

}

void SpaceShipMaterial::setColor(glm::vec4 &c)
{

}

void SpaceShipMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void SpaceShipMaterial::update(Node* o,const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
}
