// Copyright 2017 Andy Taylor

#include "objects/Button.h"

Button::Button(float _x, float _y, float _z)
: Object(_x, _y, _z, TEXTURE) {
    image_file = "data/images/hit.png";
    
    float size = 0.25f;
    width = size * 0.7 * 2;
    height = size * 2;
    rel_mesh = {
        // FRONT
        glm::vec3(size/2 * 0.7,  0.0001,  size/2),
        glm::vec3(-size/2 * 0.7,  0.0001,  size/2),
        glm::vec3(0.0,  0.0001,  0),

        glm::vec3(size/2 * 0.7,  0.0001,  size/2),
        glm::vec3(0,  0.0001,  0),
        glm::vec3(size/2 * 0.7, 0.0001,  -size/2),

        glm::vec3(-size/2 * 0.7, 0.0001,  -size/2),
        glm::vec3(size/2 * 0.7, 0.0001,  -size/2),
        glm::vec3(0.0,  0.0001,  0),

        glm::vec3(0,  0.0001,  0),
        glm::vec3(-size/2 * 0.7,  0.0001,  size/2),
        glm::vec3(-size/2 * 0.7, 0.0001,  -size/2),
    };
    
    setupGL();
}

void Button::render() {
    glBindVertexArray(vao);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
    glDisable(GL_TEXTURE_2D);
}

void Button::update() {
    if (new_hover != hover) {
        hover = new_hover;
        
        if (!hover)
            image_file = "data/images/hit.png";
        else
            image_file = "data/images/hit hover.png";

        setupGL();
    }
}

void Button::cleanup() {
    
}

void Button::setHover(bool _hover) {
    new_hover = _hover;
}

void Button::setupUVs() {
    uvs = {
        // FRONT
        glm::vec2(1, 1),
        glm::vec2(0, 1),
        glm::vec2(0.5, 0.5),
        
        glm::vec2(1, 1),
        glm::vec2(0.5, 0.5),
        glm::vec2(1, 0.0),
        
        glm::vec2(0.0, 0.0),
        glm::vec2(1.0, 0.0),
        glm::vec2(0.5, 0.5),
        
        glm::vec2(0.5, 0.5),
        glm::vec2(0.0, 1.0),
        glm::vec2(0.0, 0.0)
    };
}

