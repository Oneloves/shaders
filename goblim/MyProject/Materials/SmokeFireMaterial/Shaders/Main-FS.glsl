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
in vec3 normal;
in float lambertian;
in float specular;
in float lambertian2;
in float specular2;

void main()
{
	Color = vec4(0.545, 0.545, 0.545, 0.87);
}