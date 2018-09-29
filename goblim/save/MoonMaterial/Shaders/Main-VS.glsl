#version 430

#extension GL_ARB_shading_language_include : enable

#include "/Materials/Common/Common"
#include "/Materials/Common/Lighting/Lighting"
#line 6 


layout(std140) uniform CPU
{
	mat4 MVP;
	float TIME;
	vec3 LIGTHPOS;
};

 out gl_PerVertex {
        vec4 gl_Position;
        float gl_PointSize;
        float gl_ClipDistance[];
    };

layout (location = 0) in vec3 Position;
layout (location = 2) in vec3 Normal;
layout (location = 3) in vec3 TexCoord;

out vec3 texCoord;
out float lambertian;
out float specular;


void main()
{
	gl_Position = MVP * vec4(Position, 1.0);
		
	vec3 N = normalize(Normal);
	vec3 L = normalize(LIGTHPOS - vec3(gl_Position.x, gl_Position.y, gl_Position.z));

	lambertian = max(dot(N, L), 0.0);
	specular = 0.0;

	if(lambertian > 0.0) {
		vec3 R = reflect(-L, N); // Vector to viewer
		vec3 V = normalize(-vec3(gl_Position.x, gl_Position.y, gl_Position.z));

		float specAngle = max(dot(R, V), 0.0);
		specular = pow(specAngle, 10);
	}

	texCoord = TexCoord;
}