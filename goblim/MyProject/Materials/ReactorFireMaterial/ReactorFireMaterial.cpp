#include "ReactorFireMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


ReactorFireMaterial::ReactorFireMaterial(std::string name):
	MaterialGL(name,"ReactorFireMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
}

ReactorFireMaterial::~ReactorFireMaterial()
{

}

void ReactorFireMaterial::setColor(glm::vec4 &c)
{

}

void ReactorFireMaterial::render(Node *o)
{
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
	glDisable(GL_BLEND);
}

void ReactorFireMaterial::update(Node* o,const int elapsedTime)
{
}
