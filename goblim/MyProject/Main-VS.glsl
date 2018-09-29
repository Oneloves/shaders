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

 out gl_PerVertex {
        vec4 gl_Position;
        float gl_PointSize;
        float gl_ClipDistance[];
    };
layout (location = 0) in vec3 Position;
layout (location = 2) in vec3 Normal;

out vec4 v_Color;

vec3 lightPos = vec3(0, 30, 0);
vec3 diffuseColor = vec3(1, 1, 1);
vec3 specColor = vec3(1.0, 1.0, 1.0);


void main()
{

	gl_Position = MVP * vec4(Position.x, Position.y, Position.z, 1.0);
	vec3 vertPos = vec3(gl_Position) / gl_Position.w;
	vec3 lightDir = normalize(lightPos - vertPos);
	vec3 reflectDir = reflect(-lightDir, Normal);
	vec3 viewDir = normalize(-vertPos);

	float lambertian = max(dot(lightDir,Normal), 0.0);
	float specular = 0.0;
	
	if(lambertian > 0.0) {
		float specAngle = max(dot(reflectDir, viewDir), 0.0);
	    specular = pow(specAngle, 4.0);
	}


	/*********/
	v_Color = vec4(lambertian*diffuseColor + specular*specColor, 1.0);
}