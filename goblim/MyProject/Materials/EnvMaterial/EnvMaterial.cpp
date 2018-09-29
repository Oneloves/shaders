#include "EnvMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


EnvMaterial::EnvMaterial(std::string name) :
	MaterialGL(name, "EnvMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = fp->uniforms()->getGPUfloat("TIME");
	lightPos = vp->uniforms()->getGPUvec3("LIGHTPOS");

	colorSampler = fp->uniforms()->getGPUsampler("colorTex");
	colorSampler2 = fp->uniforms()->getGPUsampler("colorTex2");
	colorTex = new GPUTexture2D(ressourceTexPath + "Aluminm5.jpg");
	colorTex2 = new GPUTexture2D(ressourceTexPath + "Aluminm5.jpg");
	colorSampler->Set(colorTex->getHandle());
	colorSampler2->Set(colorTex2->getHandle());
}

EnvMaterial::~EnvMaterial()
{

}

void EnvMaterial::setColor(glm::vec4 &c)
{

}

void EnvMaterial::render(Node *o)
{
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

void EnvMaterial::update(Node* o, const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
