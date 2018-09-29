#include "SmokeFireMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"
#include <math.h>

SmokeFireMaterial::SmokeFireMaterial(std::string name) :
	MaterialGL(name, "SmokeFireMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
}

SmokeFireMaterial::~SmokeFireMaterial()
{

}

void SmokeFireMaterial::setColor(glm::vec4 &c)
{

}

void SmokeFireMaterial::render(Node *o)
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

void SmokeFireMaterial::update(Node* o, const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
	//o->frame()->scale(glm::vec3(time->getValue()/6 + 0.005));
	/*
	if (fmod(actualTime, 2) < 1.0) {
		o->frame()->translate(glm::vec3(0, -time->getValue(), 0));
	}
	else {
		o->frame()->translate(glm::vec3(0, time->getValue(), 0));
	}

	printf("%f\n", time->getValue());
	*/
}
