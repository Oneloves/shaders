#include "DirtGroundMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


DirtGroundMaterial::DirtGroundMaterial(std::string name):
	MaterialGL(name,"DirtGroundMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

DirtGroundMaterial::~DirtGroundMaterial()
{

}

void DirtGroundMaterial::setColor(glm::vec4 &c)
{

}

void DirtGroundMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void DirtGroundMaterial::update(Node* o,const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
}
