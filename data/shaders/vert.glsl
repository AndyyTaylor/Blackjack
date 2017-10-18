#version 410

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_colour;

out vec4 frag_colour;

uniform mat4 MVP;

void main() {
    gl_Position = MVP * vec4(in_position, 1.0);
    
    frag_colour = in_colour;
}