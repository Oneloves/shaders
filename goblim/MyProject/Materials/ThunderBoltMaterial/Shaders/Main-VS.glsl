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

out vec4 position;

void main()
{
	gl_Position = MVP * vec4(Position, 1.0);
	position = vec4(Position, 1.0);
}
