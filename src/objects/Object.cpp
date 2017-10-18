// Copyright 2017 Andy Taylor

#include "objects/Object.h"

Object::Object(float _x, float _y, float _z, GLuint programID)
: position(_x, _y, _z)
, rotation(0, 0, 0)
, scale(1.0, 1.0, 1.0) {
    
}

void Object::setupGL(GLuint programID) {
    glGenBuffers(1, &pos_vbo);
    glGenBuffers(1, &col_vbo);
    glGenVertexArrays(1, &vao);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, pos_vbo);
    glBufferData(GL_ARRAY_BUFFER, rel_mesh.size() * sizeof(glm::vec3), rel_mesh.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, col_vbo);
    glBufferData(GL_ARRAY_BUFFER, colour.size() * sizeof(glm::vec4), colour.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);
}

