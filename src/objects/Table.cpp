// Copyright 2017 Andy Taylor

#include "objects/Table.h"

Table::Table(float _x, float _y, float _z, GLuint programID)
: Object(_x, _y, _z, programID) {
    float len = 2;
    
    rel_mesh = {
        glm::vec3(-len/2,  0.5,  -len/2),
        glm::vec3(-len/2,  0.5,  0),
        glm::vec3(-len/4,  0.5,  len/2),

        glm::vec3(-len/2,  0.5,  -len/2),
        glm::vec3(-len/4,  0.5,  len/2),
        glm::vec3(len/4,  0.5, len/2),

        glm::vec3(-len/2,  0.5,  -len/2),
        glm::vec3(len/4,  0.5, len/2),
        glm::vec3(len/2,  0.5,  0.0),

        glm::vec3(-len/2,  0.5,  -len/2),
        glm::vec3(len/2,  0.5,  0.0),
        glm::vec3(len/2,  0.5, -len/2),
        
        glm::vec3(-len/4,  0.5,  len/2),
        glm::vec3(-len/4,  -len/2,  len/2),
        glm::vec3(len/4,  -len/2,  len/2)
    };
    
    colour = {
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        glm::vec4(0.0, 1.0, 0.0, 1.0),
        
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0)
    };
    
    setupGL(programID);
}

void Table::render() {
    glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
}

void Table::update() {
    
}

void Table::cleanup() {
    
}

