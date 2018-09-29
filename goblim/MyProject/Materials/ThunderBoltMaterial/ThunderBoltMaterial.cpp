#include "ThunderBoltMaterial.h"
#include "Engine/Base/Node.h"
#include "Engine/Base/Scene.h"



GLuint vertexbuffer;

ThunderBoltMaterial::ThunderBoltMaterial(std::string name):
	MaterialGL(name,"ThunderBoltMaterial")
{
	modelViewProj = vp->uniforms()->getGPUmat4("MVP");
	time = vp->uniforms()->getGPUfloat("TIME");
}

ThunderBoltMaterial::~ThunderBoltMaterial()
{

}

void ThunderBoltMaterial::setColor(glm::vec4 &c)
{
	
}

void ThunderBoltMaterial::render(Node *o)
{
	modelViewProj->Set(o->frame()->getTransformMatrix());
	if (m_ProgramPipeline)
	{		
		m_ProgramPipeline->bind();
		o->drawGeometry(GL_TRIANGLES);
		m_ProgramPipeline->release();
	}
}

void ThunderBoltMaterial::update(Node* o,const int elapsedTime)
{
	float actualTime = (float)clock() / CLOCKS_PER_SEC;
	time->Set(actualTime);

}
