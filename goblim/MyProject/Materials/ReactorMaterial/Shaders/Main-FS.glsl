#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 


layout (location = 0) out vec4 Color;
in vec3 position;
in vec3 normal;
in vec2 uv;

void main()
{
	Color = vec4(1.0, 1.0, 1.0, 1.0);
}