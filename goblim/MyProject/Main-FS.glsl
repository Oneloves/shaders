#version 430

#extension GL_ARB_shading_language_include : enable
#include "/Materials/Common/Lighting/Lighting"
#line 6 



in vec4 v_Color;

layout (location = 0) out vec4 Color;

void main()
{
	
	Color = v_Color;
}