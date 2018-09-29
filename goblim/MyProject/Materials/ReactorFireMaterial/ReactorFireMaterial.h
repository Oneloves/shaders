#ifndef _REACTORFIREMATERIAL_H
#define _REACTORFIREMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class ReactorFireMaterial : public MaterialGL
{
	public:
		ReactorFireMaterial(std::string name);
		~ReactorFireMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif