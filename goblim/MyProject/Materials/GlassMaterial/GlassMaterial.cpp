#include "GlassMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


GlassMaterial::GlassMaterial(std::string name):
	MaterialGL(name,"GlassMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

GlassMaterial::~GlassMaterial()
{

}

void GlassMaterial::setColor(glm::vec4 &c)
{

}

void GlassMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void GlassMaterial::update(Node* o,const int elapsedTime)
{

}
