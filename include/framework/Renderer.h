// Copyright 2017 Andy Taylor

#include <GL/Glew.h>
#include <iostream>

class Renderer {
 public:
    Renderer(const std::string &vertShader, const std::string &fragShader);
    
    
 private:
    GLuint programID;
    
    void printShaderCompilationError(GLuint id);
    
    GLuint loadShader(const std::string &fileName, GLenum type);
    const std::string readFile(const std::string &fileName);
};


