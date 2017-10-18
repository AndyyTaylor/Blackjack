// Copyright 2017 Andy Taylor

#include "objects/Card.h"

Card::Card(float _x, float _y, float _z, GLuint programID)
: Object(_x, _y, _z, programID) {
    rel_mesh = {
        glm::vec3(0.5,  0.5,  0.5),
        glm::vec3(-0.5,  0.5,  0.5),
        glm::vec3(0.0,  0.0,  0.5),

        glm::vec3(0.5,  0.5,  0.5),
        glm::vec3(0,  0,  0.5),
        glm::vec3(0.5, -0.5,  0.5),

        glm::vec3(-0.5, -0.5,  0.5),
        glm::vec3(0.5, -0.5,  0.5),
        glm::vec3(0.0,  0.0,  0.5),

        glm::vec3(0,  0,  0.5),
        glm::vec3(-0.5,  0.5,  0.5),
        glm::vec3(-0.5, -0.5,  0.5)
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
    
}

void Card::cleanup() {
    
}
