#ifndef _TPMATERIAL_H
#define _TPMATERIAL_H


#include "Engine/OpenGL/MaterialGL.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"
#include <memory.h>

class TPMaterial : public MaterialGL
{
	public:
		TPMaterial(std::string name);
		~TPMaterial();
		void setColor(glm::vec4 &c);

		virtual void render(Node *o);
		virtual void update(Node* o,const int elapsedTime);
		GPUmat4* modelViewProj;
		GPUfloat* time;
		GPUvec3* lightPos;

};

#endif