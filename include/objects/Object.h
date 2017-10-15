// Copyright 2017 Andy Taylor

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/glew.h>

class Object {
 public:
    virtual void init() = 0;
    virtual void cleanup() = 0;

    virtual void update() = 0;
    virtual void render() = 0;
    
    void bind() { glBindBuffer(GL_ARRAY_BUFFER, vbo);}

 protected:
    float x, y, z;
    GLuint vbo;
    
    std::vector<float> rel_mesh;
    
    Object(float _x, float _y, float _z);
    
    void setupGL();
};

#endif
