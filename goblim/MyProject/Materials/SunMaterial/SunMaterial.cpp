#include "SunMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


SunMaterial::SunMaterial(std::string name):
	MaterialGL(name,"SunMaterial")
{
	
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
}

SunMaterial::~SunMaterial()
{

}

void SunMaterial::setColor(glm::vec4 &c)
{
	
}

void SunMaterial::render(Node *o)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	modelViewProj->Set(o->frame()->getTransformMatrix());
	time->Set(actualTime);

	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void SunMaterial::update(Node* o,const int elapsedTime)
{
	//o->frame()->translate(glm::vec3(15 * (cos(time->getValue())/2), 0, 15 * (sin(time->getValue()))/2));
}
