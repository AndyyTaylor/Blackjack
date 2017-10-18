// Copyright 2017 Andy Taylor

#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <GL/Glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Glm_common.h"

class Renderer {
 public:
    Renderer();
    Renderer(const std::string &vertShader, const std::string &fragShader);
    
    void activate();
    GLuint getProgramID() { return programID; }
    
    void loadMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p);
    
 private:
    GLuint programID;
    
    GLint loc_pos, loc_model, loc_view, loc_proj;
    
    void printShaderCompilationError(GLuint id);
    
    GLuint loadShader(const std::string &fileName, GLenum type);
    const std::string readFile(const std::string &fileName);
};

#endif
