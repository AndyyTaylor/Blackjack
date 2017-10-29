// Copyright 2017 Andy Taylor

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "framework/Glm_common.h"
#include "framework/Tex_Atlas.h"

enum RENDER_TYPE {COLOR, TEXTURE};

class Object {
 public:
    virtual void cleanup() = 0;

    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual void setupUVs() = 0;
    
    void bind() { glBindVertexArray(vao); }
    
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    
    std::vector<glm::vec4> colour;
    std::vector<glm::vec2> uvs;

 protected:
    GLuint pos_vbo, col_vbo, TextureID;
    GLuint vao;
    
    RENDER_TYPE render_type;
    
    std::vector<glm::vec3> rel_mesh;
    std::string image_file;
    
    Object(float _x, float _y, float _z, RENDER_TYPE r_type);
    
    void setupGL();
};

#endif
