// Copyright 2017 Andy Taylor

#include "ui/ImageOverlay.h"
#include "framework/Display.h"

ImageOverlay::ImageOverlay(float _x, float _y, float _z, std::string file)
: Object(_x, _y, _z, TEXTURE) {
    image_file = file;
    
    float size = 0.1f;
    rel_mesh = {
        // FRONT
        glm::vec3(size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  size/2,  0.0001),
        glm::vec3(-size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  size/2,  0.0001),
        glm::vec3(0.0,  0,  0.0001),

        glm::vec3(size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  size/2,  0.0001),
        glm::vec3(0,  0,  0.0001),
        glm::vec3(size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  -size/2, 0.0001),

        glm::vec3(-size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  -size/2, 0.0001),
        glm::vec3(size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  -size/2, 0.0001),
        glm::vec3(0.0,  0,  0.0001),

        glm::vec3(0,  0,  0.0001),
        glm::vec3(-size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  size/2,  0.0001),
        glm::vec3(-size/2 * (1/(1.0f * Display::WIDTH / Display::HEIGHT)),  -size/2, 0.0001)
    };
    
    setupGL();
}

void ImageOverlay::update() {
    
}

void ImageOverlay::render() {
    glBindVertexArray(vao);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    glEnable(GL_TEXTURE_2D);
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
    glDisable(GL_TEXTURE_2D);
}

void ImageOverlay::cleanup() {
    
}

void ImageOverlay::setupUVs() {
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
