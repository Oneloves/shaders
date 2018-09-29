#include "TPMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


TPMaterial::TPMaterial(std::string name):
	MaterialGL(name,"TPMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
	lightPos = vp->uniforms()->getGPUvec3("LIGHTPOS");
}

TPMaterial::~TPMaterial()
{

}

void TPMaterial::setColor(glm::vec4 &c)
{

}

void TPMaterial::render(Node *o)
{
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//o->frame()->rotate(glm::vec3(0, 0.2, 0), 0.01);
	modelViewProj->Set(o->frame()->getTransformMatrix());
	lightPos->Set(glm::vec3(0, 0, 0));

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
	//glDisable(GL_BLEND);
}

void TPMaterial::update(Node* o,const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
