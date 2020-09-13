#version 400

in vec3 surfaceNormal;
in vec3 toLightVector;

out vec4 screen_color;

uniform vec3 lightColor;

void main(void)
{
    vec3 unitNormal  = normalize(surfaceNormal);
	vec3 unitLightVector = normalize(toLightVector);

	float nDot1 = dot(unitNormal, unitLightVector);
	float brightness = max(nDot1, 0.2);

	vec3 diffuse = brightness * lightColor;

    screen_color = vec4(diffuse, 1.0) * vec4(0.f, 1.f, 0.f, 1.f);
}