// Copyright 2017 Andy Taylor

#include "objects/Card.h"

Card::Card(float _x, float _y, float _z, SUIT _suit, FACE _face)
: Object(_x, _y, _z, TEXTURE)
, suit(_suit)
, face(_face) {
    float size = 0.25f;
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
        
        // BACK
        glm::vec3(size/2 * 0.7,  -0.0001,  size/2),
        glm::vec3(-size/2 * 0.7,  -0.0001,  size/2),
        glm::vec3(0.0,  -0.0001,  0),

        glm::vec3(size/2 * 0.7,  -0.0001,  size/2),
        glm::vec3(0,  -0.0001,  0),
        glm::vec3(size/2 * 0.7, -0.0001,  -size/2),

        glm::vec3(-size/2 * 0.7, -0.0001,  -size/2),
        glm::vec3(size/2 * 0.7, -0.0001,  -size/2),
        glm::vec3(0.0,  -0.0001,  0),

        glm::vec3(0,  -0.0001,  0),
        glm::vec3(-size/2 * 0.7,  -0.0001,  size/2),
        glm::vec3(-size/2 * 0.7, -0.0001,  -size/2)
    };
    
    setupGL();
}

void Card::render() {
    glBindVertexArray(vao);
    glEnable(GL_TEXTURE_2D);
    glDrawArrays(GL_TRIANGLES, 0, rel_mesh.size());
    glDisable(GL_TEXTURE_2D);
}

void Card::update() {
    if (glide_tick > 0) {
        position += dpos;
        rotation += drot;
        
        glide_tick -= 1;
    }
}

void Card::cleanup() {
    
}

void Card::setupUVs() {
    uvs = {
        // FRONT
        Tex_Atlas::mapUVs(face, suit, 1, 1),
        Tex_Atlas::mapUVs(face, suit, 0, 1),
        Tex_Atlas::mapUVs(face, suit, 0.5, 0.5),
        
        Tex_Atlas::mapUVs(face, suit, 1, 1),
        Tex_Atlas::mapUVs(face, suit, 0.5, 0.5),
        Tex_Atlas::mapUVs(face, suit, 1, 0.0),
        
        Tex_Atlas::mapUVs(face, suit, 0.0, 0.0),
        Tex_Atlas::mapUVs(face, suit, 1.0, 0.0),
        Tex_Atlas::mapUVs(face, suit, 0.5, 0.5),
        
        Tex_Atlas::mapUVs(face, suit, 0.5, 0.5),
        Tex_Atlas::mapUVs(face, suit, 0.0, 1.0),
        Tex_Atlas::mapUVs(face, suit, 0.0, 0.0),
        
        // BACK
        Tex_Atlas::mapUVs(ACE, BACK, 1, 1),
        Tex_Atlas::mapUVs(ACE, BACK, 0, 1),
        Tex_Atlas::mapUVs(ACE, BACK, 0.5, 0.5),
        
        Tex_Atlas::mapUVs(ACE, BACK, 1, 1),
        Tex_Atlas::mapUVs(ACE, BACK, 0.5, 0.5),
        Tex_Atlas::mapUVs(ACE, BACK, 1, 0.0),
        
        Tex_Atlas::mapUVs(ACE, BACK, 0.0, 0.0),
        Tex_Atlas::mapUVs(ACE, BACK, 1.0, 0.0),
        Tex_Atlas::mapUVs(ACE, BACK, 0.5, 0.5),
        
        Tex_Atlas::mapUVs(ACE, BACK, 0.5, 0.5),
        Tex_Atlas::mapUVs(ACE, BACK, 0.0, 1.0),
        Tex_Atlas::mapUVs(ACE, BACK, 0.0, 0.0)
    };
}

void Card::glide(glm::vec3 new_pos, glm::vec3 new_rot, int ticks) {
    dpos = (new_pos - position) / glm::vec3(ticks, ticks, ticks);
    drot = (new_rot - rotation) / glm::vec3(ticks, ticks, ticks);
    glide_tick = ticks;
}
