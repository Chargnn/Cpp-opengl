#version 400

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 surfaceNormal;
out vec3 toLightVector;

uniform mat4 view;
uniform mat4 transform;
uniform mat4 projection;

uniform vec3 lightPosition;

void main(void)
{
	vec4 worldPosition = transform * vec4(position,1.0);

    gl_Position = projection * view * worldPosition;

    surfaceNormal = (transform * vec4(normal, 0.0)).xyz;
    toLightVector = lightPosition - worldPosition.xyz;
}