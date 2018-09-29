#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 

in vec3 texCoord;
in float lambertian;
in float specular;

uniform sampler2D SAMPLER;

layout (location = 0) out vec4 Color;

void main()
{

	vec2 tCoord = texCoord.xy;
	Color =  texture (SAMPLER, tCoord.xy);
	
	float Ka = 1.0;
	float Kd = 1.0;
	float Ks = 1.0;

	vec3 ambientColor = vec3(Color.r, Color.g, Color.b);
	vec3 diffuseColor = vec3(1, 1, 1);
	vec3 specularColor = vec3(1, 1, 1);

	Color = vec4(Ka * ambientColor + Kd * lambertian * diffuseColor + Ks * specular * specularColor, 1.0);
	
}