// Copyright 2017 Andy Taylor

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "framework/Glm_common.h"

class Object {
 public:
    virtual void cleanup() = 0;

    virtual void update() = 0;
    virtual void render() = 0;
    
    void bind() { glBindVertexArray(vao); }
    
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

 protected:
    GLuint vbo;
    GLuint vao;
    
    std::vector<glm::vec3> rel_mesh;
    
    Object(float _x, float _y, float _z, GLuint programID);
    
    void setupGL(GLuint programID);
};

#endif
