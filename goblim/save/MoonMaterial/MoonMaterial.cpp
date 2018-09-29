#include "MoonMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"


MoonMaterial::MoonMaterial(std::string name):
	MaterialGL(name,"MoonMaterial")
{
	
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	lightPos = vp->uniforms()->getGPUvec3("LIGTHPOS");
	time = vp->uniforms()->getGPUfloat("TIME");
	sampler = fp->uniforms()->getGPUsampler("SAMPLER");
	texture2D = new GPUTexture2D(ressourceTexPath+"MoonDiffuse.jpg");

	sampler->Set(texture2D->getHandle());
	lightPos->Set(glm::vec3(0.0, 0.0, 0.0));
}

MoonMaterial::~MoonMaterial()
{

}

void MoonMaterial::setColor(glm::vec4 &c)
{
	
}

void MoonMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}

}

void MoonMaterial::update(Node* o,const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);
}
