// Copyright 2017 Andy Taylor

#include "objects/Object.h"

Object::Object(float _x, float _y, float _z)
: x(_x), y(_y), z(_z) {
    setupGL();
}

void Object::setupGL() {
    glGenBuffers(1, &vbo);
}

