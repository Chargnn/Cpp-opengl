#version 400

in vec3 surfaceNormal;
in vec3 toLightVector;

out vec4 screen_color;

uniform vec3 lightColor;
uniform vec3 lightAttenuation;

void main(void)
{
    float lightDistance = length(toLightVector);
    float attenuationFactor = lightAttenuation.x + lightAttenuation.y * lightDistance + lightAttenuation.z * lightDistance * lightDistance;
    vec3 unitNormal  = normalize(surfaceNormal);
	vec3 unitLightVector = normalize(toLightVector);

	float nDot1 = dot(unitNormal, unitLightVector);
	float brightness = max(nDot1, 0.2);

	vec3 diffuse = (brightness * lightColor) / attenuationFactor;

    screen_color = vec4(diffuse, 1.0) * vec4(0.f, 1.f, 0.f, 1.f);
}