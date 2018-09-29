#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Common"
#include "/Materials/Common/Lighting/Lighting"
#line 6 

layout(std140) uniform CPU
{
	mat4 MVP;
	float TIME;
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


float hash(float x)
{
	return fract(sin(x) * 43758.5453);
}

void main()
{
	float time = TIME;
	vec2 x = position.xy;
	float a = abs(cos(time + mix(Normal.x, Normal.y, Normal.z) * 40));

	vec3 newPosition = vec3(Position.x, Position.y * a, Position.z);

	gl_Position = MVP * vec4(newPosition, 1.0);
	position = newPosition.xyz;
	normal = Normal.xyz;
	uv = UV;

	/*

	vec2 x = position.xy;
	vec3 a = vec3(max((fract(dot(sin(x), x)) - 0.99) * 50.0 + mix(0.4, 1.2, sin(TIME - hash(position.x + position.y)) * 0.5 + 0.5) - 0.5, 0.0));
	*/
}
