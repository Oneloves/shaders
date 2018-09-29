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
	float Kd = 1.5;
	float Ks = 1.8;

	vec3 diffuseColor = vec3(0.945, 0.376, 0.109);
	vec3 specularColor = vec3(1.0, 1.0, 1.0);

	vec3 diffuseColor2 = vec3(0.392, 0.003, 0.223);
	vec3 specularColor2 = vec3(0.2, 0.2, 0.2);

	vec4 Color1 = vec4(Kd * lambertian * diffuseColor + Ks * specular * specularColor, 0.65);
	vec4 Color2 = vec4(Kd * lambertian2 * diffuseColor2 + Ks * specular2 * specularColor2, 0.65);

	vec4 color = Color1 * 0.5 + Color2 * (1 - 0.5);
	Color = mix(vec4(0.0, 0.0, 0.0, 1.0), color, 0.7);
	Color = vec4(1.0, 1.0, 0.0, 0.1);
}