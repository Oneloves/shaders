/*#include "TPMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


TPMaterial::TPMaterial(std::string name) :
	MaterialGL(name, "TPMaterial")
{

	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = vp->uniforms()->getGPUfloat("TIME");

}
TPMaterial::~TPMaterial()
{

}

void TPMaterial::setColor(glm::vec4 &c)
{

}

void TPMaterial::render(Node *o)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	o->frame()->rotate(glm::vec3(4.0, 0, 0), 0.01);
	modelViewProj->Set(o->frame()->getTransformMatrix());
	time->Set(actualTime);

	if (m_ProgramPipeline)
	{
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void TPMaterial::update(Node* o, const int elapsedTime)
{



}
*/