#version 430 core
#extension GL_ARB_shading_language_include : enable
#include "/Materials/Common/Lighting/Lighting"
#line 3 




layout(std140) uniform CPU
{
	mat4 NormalMV;
	mat4 modelMatrix;
};

in vec3 texCoord;
in vec3 position;
in mat3 TSpace;
in vec3 lightDir;
in vec3 viewDir;
in vec3 normal;

uniform sampler2D normalTex;
uniform sampler2D colorTex;
uniform sampler2D specTex;


layout(location = 0) out vec4 Color;
void main()
{
	/*
	vec2 tCoord = texCoord.xy;

	vec4 color = texture(colorTex, tCoord.xy);
	vec4 normalSample = texture(normalTex, tCoord.xy);
	vec4 specSample = texture(specTex, tCoord.xy);

	vec4 normalFromTSPace = vec4(TSpace * (normalSample.xyz*2.0 - 1.0), 0.0);
	vec3 normal = (NormalMV * normalFromTSPace).xyz;

	vec3 reflectDir = reflect(-lightDir, normal);
	float lambertian = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;

	vec3 MaterialDiffuseColor = color.rgb;
	vec3 MaterialAmbientColor = vec3(0.4, 0.4, 0.4) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = specSample.rgb;

	if (lambertian > 0.0) {
		float specAngle = max(dot(reflectDir, viewDir), 0.0);
		specular = pow(specAngle, 2.0);
	}

	Color.r = MaterialDiffuseColor.r * lambertian + MaterialSpecularColor.r;
	Color.g = MaterialDiffuseColor.g * lambertian + MaterialSpecularColor.g;
	Color.b = MaterialDiffuseColor.b * lambertian + MaterialSpecularColor.b;
	*/

	// Light properties
	vec3 LightPosition = vec3(10.0, 10.0, 10.0);
	vec3 LightColor = vec3(1, 1, 1);

	// Material properties
	vec2 tCoord = texCoord.xy;
	vec3 MaterialDiffuseColor = texture(colorTex, tCoord.xy).rgb + 0.19;
	vec3 MaterialAmbientColor = vec3(0.2, 0.2, 0.2) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = texture(specTex, tCoord.xy).rgb;

	vec3 normalSample = texture(normalTex, tCoord.xy).rgb;

	vec3 N = normalize(normalSample);
	vec3 L = normalize(LightPosition - vec3(tCoord.x, tCoord.y, N.z));

	float lambertian = max(dot(N, L), 0.0);
	float specular = 0.0;

	if (lambertian > 0.0) {
		vec3 R = reflect(-L, N);
		vec3 V = normalize(-vec3(position.x, position.y, position.z));

		float specAngle = max(dot(R, V), 0.0);
		specular = pow(specAngle, 15);
	}

	Color = vec4(MaterialAmbientColor + MaterialDiffuseColor * LightColor * lambertian + MaterialSpecularColor * LightColor * specular, 1.0);

}