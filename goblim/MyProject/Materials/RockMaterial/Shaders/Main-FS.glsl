#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 

layout(std140) uniform CPU
{
	float TIME;
};

layout(location = 0) out vec4 Color;
in vec3 position;
in vec3 normal;

void main()
{
	// Sun Light
	// Light properties
	vec3 LightPosition = vec3(0.0, 10.0, -500.0);
	vec3 LightColor = vec3(1, 1, 1);

	// Material properties
	vec3 MaterialDiffuseColor = vec3(0.63, 0.63, 0.458);
	vec3 MaterialAmbientColor = vec3(0.3, 0.3, 0.3) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.0, 0.0, 0.0);

	vec3 N = normalize(normal);
	vec3 L = normalize(LightPosition - vec3(position.x, position.y, position.z));

	float lambertian = max(dot(N, L), 0.0);
	float specular = 0.0;

	if (lambertian > 0.0) {
		vec3 R = reflect(-L, N);
		vec3 V = normalize(-vec3(position.x, position.y, position.z));

		float specAngle = max(dot(R, V), 0.0);
		specular = pow(specAngle, 15);
	}

	Color = vec4(MaterialAmbientColor + MaterialDiffuseColor * LightColor * lambertian + MaterialSpecularColor * LightColor * specular, 1.0);


	// Campfire light
	// Light properties
	float LightPower = 10.0f + cos(TIME + mix(normal.x, normal.y, normal.z) * 40) * 2;
	vec3 LightPosition2 = vec3(2.0, 0.02, -1.5);
	vec3 LightColor2 = vec3(1, 1, 0);

	// Material properties
	vec3 MaterialDiffuseColor2 = vec3(0.63, 0.63, 0.458);
	vec3 MaterialAmbientColor2 = vec3(0.3, 0.3, 0.3) * MaterialDiffuseColor2;
	vec3 MaterialSpecularColor2 = vec3(1.0, 1.0, 1.0);

	float distance = length(LightPosition2 - position);

	vec3 N2 = normalize(normal);
	vec3 L2 = normalize(LightPosition2 - vec3(position.x, position.y, position.z));

	float lambertian2 = max(dot(N2, L2), 0.0);
	float specular2 = 0.0;

	if (lambertian2 > 0.0) {
		vec3 R2 = reflect(-L2, N2);
		vec3 V2 = normalize(-vec3(position.x, position.y, position.z));

		float specAngle2 = max(dot(R2, V2), 0.0);
		specular2 = pow(specAngle2, 25);
	}	
	
	Color += vec4(MaterialAmbientColor2 
		+ MaterialDiffuseColor2 * LightColor2 * LightPower * lambertian2 / (distance*distance)
		+ MaterialSpecularColor2 * LightColor2 * LightPower * specular2 / (distance*distance), 1.0);

}