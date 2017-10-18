// Copyright 2017 Andy Taylor
#ifndef MATRIX_H_
#define MATRIX_H_

#include "Glm_common.h"

class Object;

namespace Maths {
    glm::mat4 createViewMatrix(const Object& cam);
    glm::mat4 createModelMatrix(const Object &obj);
    glm::mat4 createProjMatrix();
}

#endif /* MATRIX_H_ */
