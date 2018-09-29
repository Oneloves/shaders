#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 

float polygonDistance(vec2 p, float radius, float angleOffset, int sideCount) {
	float a = atan(p.x, p.y) + angleOffset;
	float b = 6.28319 / float(sideCount);
	return cos(floor(.5 + a / b) * b - a) * length(p) - radius;
}


float hash(float x)
{
	return fract(sin(x) * 43758.5453);
}

#define HASHSCALE1 443.8975
float hash11(float p) // assumes p in ~0-1 range
{
	vec3 p3 = fract(vec3(p) * HASHSCALE1);
	p3 += dot(p3, p3.yzx + 19.19);
	return fract((p3.x + p3.y) * p3.z);
}

#define HASHSCALE3 vec3(.1031, .1030, .0973)
vec2 hash21(float p) // assumes p in larger integer range
{
	vec3 p3 = fract(vec3(p) * HASHSCALE3);
	p3 += dot(p3, p3.yzx + 19.19);
	return fract(vec2((p3.x + p3.y)*p3.z, (p3.x + p3.z)*p3.y));
}

layout(std140) uniform CPU
{
	float TIME;
};

layout(location = 0) out vec4 Color;

uniform sampler2D colorTex;
uniform sampler2D colorTex2;

in vec4 position;
in vec3 texCoord;

void main()
{
	float time = floor(TIME + 0.5) - TIME;
	vec2 x = position.xy;
	vec3 a = vec3(max((fract(dot(sin(x), x)) - 0.99) * 50.0 + mix(0.4, 1.2, sin(TIME - hash(position.x + position.y)) * 0.5 + 0.5) - 0.5, 0.0));
	
	

	/*-------------------------------------------*/
	vec2 uv = vec2(0.3) - position.xy*0.05;
	uv.x *= 0.2;

	float accum = 0.;
	for (int i = 0; i < 15; i++) {
		float fi = float(i);
		float thisYOffset = mod(hash11(fi * 0.017) * (10 + 19.) * 0.2, 4.0) - 2.0;
		vec2 center = (hash21(fi) * 2. - 1.) * vec2(1.1, 1.0) - vec2(0.0, thisYOffset);
		float radius = 0.5;
		vec2 offset = uv - center;
		float twistFactor = (hash11(fi * 0.0347) * 2. - 1.) * 1.9;
		float rotation = 0.1 + 10 * 0.2 + sin(10 * 0.1) * 0.9 + (length(offset) / radius) * twistFactor;
		accum += pow(smoothstep(radius, 0.0, polygonDistance(uv - center, 0.1 + hash11(fi * 2.3) * 0.2, rotation, 5) + 0.1), 3.0);
	}

	vec3 subColor = vec3(0.6, 0.8, 0.2);
	vec3 addColor = vec3(0.3, 0.1, 0.2);

	Color = vec4(vec3(a) - accum * subColor + addColor, 1.0);

}