#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Common"
#include "/Materials/Common/Lighting/Lighting"
#line 6 

layout(std140) uniform CPU
{
	mat4 MVP;
};


out gl_PerVertex{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
};


layout(location = 0) in vec3 Position;
layout(location = 1) in vec2 UV;
layout(location = 2) in vec3 Normal;

out vec3 position;
out vec3 normal;
out vec2 uv;

void main()
{
	gl_Position = MVP * vec4(Position, 1.0);
	position = Position.xyz;
	normal = Normal.xyz;
	uv = UV;
}
