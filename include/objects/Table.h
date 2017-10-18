// Copyright 2017 Andy Taylor

#ifndef TABLE_H_DEFINED
#define TABLE_H_DEFINED

#include "objects/Object.h"

class Table : public Object {
 public:
    Table(float _x, float _y, float _z, GLuint programID);
    
    void render();
    void update();
    void cleanup();
};


#endif


