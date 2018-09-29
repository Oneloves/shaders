#ifndef _SPACESHIPMATERIAL_H
#define _SPACESHIPMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class SpaceShipMaterial : public MaterialGL
{
	public:
		SpaceShipMaterial(std::string name);
		~SpaceShipMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;

};

#endif