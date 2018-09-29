#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Lighting/Lighting"
#line 6 


layout (location = 0) out vec4 Color;
in vec3 position;
in vec3 normal;
in vec2 uv;

void main()
{
	// Light properties
	vec3 LightPosition = vec3(2.3, 10.0, -1.5);
	vec3 LightColor = vec3(1.0, 1.0, 0.0);

	// Material properties
	vec3 MaterialDiffuseColor = vec3(1.0, 0.6, 0.101);
	vec3 MaterialAmbientColor = vec3(1.0, 0.3, 0.25) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.8, 0.2, 0.1);

	vec3 N = normalize(normal);
	vec3 L = normalize(LightPosition - vec3(position.x, position.y, position.z));

	float lambertian = max(dot(N, L), 0.0);
	float specular = 0.0;

	if (lambertian > 0.0) {
		vec3 R = reflect(-L, N);
		vec3 V = normalize(-vec3(position.x, position.y, position.z));

		float specAngle = max(dot(R, V), 0.0);
		specular = pow(specAngle, 1);
	}

	Color = vec4(MaterialAmbientColor + MaterialDiffuseColor * LightColor * lambertian + MaterialSpecularColor * LightColor * specular, 0.85);
}