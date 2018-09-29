#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 


layout(std140) uniform CPU
{
	float TIME;
};

layout (location = 0) out vec4 Color;
in vec4 position;

void main()
{
	vec2 x = position.xy;
	vec3 a = vec3(max((fract(dot(sin(x),x))-0.99)*90.0,0.0));

    Color = vec4(a, 1.0);
}