#include "ReactorMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


ReactorMaterial::ReactorMaterial(std::string name):
	MaterialGL(name,"ReactorMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

ReactorMaterial::~ReactorMaterial()
{

}

void ReactorMaterial::setColor(glm::vec4 &c)
{

}

void ReactorMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void ReactorMaterial::update(Node* o,const int elapsedTime)
{
}
