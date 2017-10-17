// Copyright 2017 Andy Taylor

#include "objects/Card.h"

Card::Card(float _x, float _y, float _z)
: Object(_x, _y, _z) {
    rel_mesh.push_back(-0.5);
    rel_mesh.push_back(-0.5);
    rel_mesh.push_back(1);
    rel_mesh.push_back(-0.5);
    rel_mesh.push_back(0.5);
    rel_mesh.push_back(1);
    rel_mesh.push_back(0.5);
    rel_mesh.push_back(0.5);
    rel_mesh.push_back(1);
    rel_mesh.push_back(0.5);
    rel_mesh.push_back(-0.5);
    rel_mesh.push_back(1);
}

void Card::render() {
    bind();
    std::cout << "Render" << std::endl;
    
    GLuint bo;
    glGenBuffers(1, &bo);
    glBindBuffer(GL_ARRAY_BUFFER, bo);
    GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // glBufferData(GL_ARRAY_BUFFER, rel_mesh.size() * sizeof(float), rel_mesh.data(), GL_STATIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Card::update() {
    
}

void Card::cleanup() {
    
}
