#include "GrassGroundMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


GrassGroundMaterial::GrassGroundMaterial(std::string name):
	MaterialGL(name,"GrassGroundMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

GrassGroundMaterial::~GrassGroundMaterial()
{

}

void GrassGroundMaterial::setColor(glm::vec4 &c)
{

}

void GrassGroundMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void GrassGroundMaterial::update(Node* o,const int elapsedTime)
{

}
