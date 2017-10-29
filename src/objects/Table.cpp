// Copyright 2017 Andy Taylor
// https://www.turbosquid.com/FullPreview/Index.cfm/ID/1012557

#include "objects/Table.h"

Table::Table(float _x, float _y, float _z)
: Object(_x, _y, _z, COLOR) {
    float len = 3;
    
    rel_mesh = {
        glm::vec3(0 - 2,  0,  0 - 1),
        glm::vec3(0 - 2,  0,  1 - 1),
        glm::vec3(1 - 2,  0,  2 - 1),
        
        glm::vec3(0 - 2,  0,  0 - 1),
        glm::vec3(1 - 2,  0,  2 - 1),
        glm::vec3(3 - 2,  0,  2 - 1),
        
        glm::vec3(0 - 2,  0,  0 - 1),
        glm::vec3(3 - 2,  0,  2 - 1),
        glm::vec3(4 - 2,  0,  1 - 1),
        
        glm::vec3(0 - 2,  0,  0 - 1),
        glm::vec3(4 - 2,  0,  1 - 1),
        glm::vec3(4 - 2,  0,  0 - 1)
    };
    /*rel_mesh = {
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
        glm::vec3(len/4,  -len/2,  len/2),
        
        glm::vec3(-len/4,  0.5,  len/2),
        glm::vec3(len/4,  -len/2,  len/2),
        glm::vec3(len/4,  0.5,  len/2)
    };*/
    
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
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0),
        glm::vec4(0.35, 0.15, 0.15, 1.0)
    };
    
    setupGL();
}

void Table::render() {
    glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
}

void Table::update() {
    
}

void Table::cleanup() {
    
}

