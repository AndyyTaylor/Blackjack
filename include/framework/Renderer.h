// Copyright 2017 Andy Taylor

#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <GL/Glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

class Renderer {
 public:
    Renderer();
    Renderer(const std::string &vertShader, const std::string &fragShader);
    
    void activate();
    
 private:
    GLuint posLocation;
    GLuint programID;
    GLuint vao;
    GLuint vbo;
    
    void printShaderCompilationError(GLuint id);
    
    GLuint loadShader(const std::string &fileName, GLenum type);
    const std::string readFile(const std::string &fileName);
};

#endif
