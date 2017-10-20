// Copyright 2017 Andy Taylor

#include "objects/Card.h"

Card::Card(float _x, float _y, float _z, GLuint programID)
: Object(_x, _y, _z, programID) {
    float size = 0.25f;
    rel_mesh = {
        glm::vec3(size/2 * 0.7,  0,  size/2),
        glm::vec3(-size/2 * 0.7,  0,  size/2),
        glm::vec3(0.0,  0,  0),

        glm::vec3(size/2 * 0.7,  0,  size/2),
        glm::vec3(0,  0,  0),
        glm::vec3(size/2 * 0.7, 0,  -size/2),

        glm::vec3(-size/2 * 0.7, 0,  -size/2),
        glm::vec3(size/2 * 0.7, 0,  -size/2),
        glm::vec3(0.0,  0,  0),

        glm::vec3(0,  0,  0),
        glm::vec3(-size/2 * 0.7,  0,  size/2),
        glm::vec3(-size/2 * 0.7, 0,  -size/2)
    };
    
    colour = {
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0),
        glm::vec4(0.0, 0.0, 1.0, 1.0)
    };
    
    setupGL(programID);
}

void Card::render() {
    glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
}

void Card::update() {
    if (glide_tick > 0) {
        position += dpos;
        rotation += drot;
        
        glide_tick -= 1;
    }
}

void Card::cleanup() {
    
}

void Card::glide(glm::vec3 new_pos, glm::vec3 new_rot, int ticks) {
    dpos = (new_pos - position) / glm::vec3(ticks, ticks, ticks);
    drot = (new_rot - rotation) / glm::vec3(ticks, ticks, ticks);
    glide_tick = ticks;
}
