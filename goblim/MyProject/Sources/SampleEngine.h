/*
 *	(c) XLim, UMR-CNRS
 *	Authors: G.Gilet
 *
 */

#ifndef _SAMPLE_ENGINE_H
#define _SAMPLE_ENGINE_H

#include <map>
#include <string>
#include "Engine/OpenGL/EngineGL.h"
#include "Effects/Blur/Blur.h"
#include "Effects/PostProcess/AntiAliasing/AntiAliasing.h"

class SampleEngine : public EngineGL
{
	public:
		SampleEngine(int width, int height);
		~SampleEngine();

		virtual bool init(std::string filename = "");
		virtual void render();
		virtual void animate(const int elapsedTime);
		
	protected:
		GPUFBO* fboTest;
		AntiAliasing* antiAliasing;
		Blur* blur;
};
#endif