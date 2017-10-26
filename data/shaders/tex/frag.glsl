#version 410

in vec2 UV;

out vec3 out_colour;

uniform sampler2D myTextureSampler;

void main() {
    out_colour = texture(myTextureSampler, UV).rgb;
}
