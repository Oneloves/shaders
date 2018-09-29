#ifndef _REACTORMATERIAL_H
#define _REACTORMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class ReactorMaterial : public MaterialGL
{
	public:
		ReactorMaterial(std::string name);
		~ReactorMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif