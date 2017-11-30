// Copyright 2017 Andy Taylor

#include "objects/Object.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "framework/stb_image.h"
#endif

extern std::string PROJECT_PATH;

Object::Object(float _x, float _y, float _z, RENDER_TYPE r_type)
: position(_x, _y, _z)
, rotation(0, 0, 0)
, scale(1.0, 1.0, 1.0)
, render_type(r_type) {

}

void Object::setupGL() {
    glGenBuffers(1, &pos_vbo);
    glGenBuffers(1, &col_vbo);
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, pos_vbo);
    glBufferData(GL_ARRAY_BUFFER, rel_mesh.size() * sizeof(glm::vec3), rel_mesh.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    if (render_type == COLOR) {
        glBindBuffer(GL_ARRAY_BUFFER, col_vbo);     // TODO: col_vbo should be more generic
        glBufferData(GL_ARRAY_BUFFER, colour.size() * sizeof(glm::vec4), colour.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
    } else {
        int w, h, comp;
        unsigned char* image = stbi_load((PROJECT_PATH + "/" + image_file).c_str(), &w, &h, &comp, 4);

        if (image == nullptr)
            std::cout << "Load Failed" << '\n';

        Tex_Atlas::setTotalDimensions(w, h);
        setupUVs();

        glGenTextures(1, &TextureID);

        glBindTexture(GL_TEXTURE_2D, TextureID);

        if (comp == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        else if (comp == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        /*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/

        glBindBuffer(GL_ARRAY_BUFFER, col_vbo);
        glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), uvs.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
    }
}

