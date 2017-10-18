// Copyright 2017 Andy Taylor
#include "framework/Matrix.h"

#include "framework/Glm_common.h"
#include "objects/Object.h"
#include "framework/Display.h"

namespace Maths {
    glm::mat4 createViewMatrix(const Object& cam) {
        glm::mat4 matrix;

        matrix = glm::rotate(matrix, glm::radians(cam.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(cam.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(cam.rotation.z), {0, 0, 1});

        matrix = glm::translate(matrix, -cam.position);
        return matrix;
    }

    glm::mat4 createModelMatrix(const Object& obj) {
        glm::mat4 matrix;

        matrix = glm::translate(matrix, obj.position);

        matrix = glm::rotate(matrix, glm::radians(obj.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(obj.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(obj.rotation.z), {0, 0, 1});

        matrix = glm::scale(matrix, glm::vec3(obj.scale.x, obj.scale.y,
                                              obj.scale.z));

        return matrix;
    }

    glm::mat4 createProjMatrix() {
        return glm::perspective(glm::radians(90.0f),
                                static_cast<float>(Display::WIDTH) / static_cast<float>(Display::HEIGHT),
                                0.1f, 10000.0f);
    }
}   // namespace Maths
