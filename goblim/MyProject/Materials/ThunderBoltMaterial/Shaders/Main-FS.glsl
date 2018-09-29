#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 

layout(std140) uniform CPU
{
	float TIME;
};

layout(location = 0) out vec4 Color;

in vec4 position;


void main()
{
	Color = vec4(0.8, 0.876, 1.0, 1.0);
}