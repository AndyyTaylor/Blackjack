// Copyright 2017 Andy Taylor

#include "objects/Card.h"

Card::Card(float _x, float _y, float _z)
: Object(_x, _y, _z) {
    
}

void Card::render() {
    glBufferData(GL_ARRAY_BUFFER, rel_mesh.size() * sizeof(float), rel_mesh.data(), GL_STATIC_DRAW);
}
