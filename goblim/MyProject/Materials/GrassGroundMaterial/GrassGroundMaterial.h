#ifndef _GRASSGROUNDMATERIAL_H
#define _GRASSGROUNDMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class GrassGroundMaterial : public MaterialGL
{
	public:
		GrassGroundMaterial(std::string name);
		~GrassGroundMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
};

#endif