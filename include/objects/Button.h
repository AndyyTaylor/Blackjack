// Copyright 2017 Andy Taylor

#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "objects/Object.h"

class Button : public Object {
 private:
    
 public:
    Button(float _x, float _y, float _z);
    
    void render();
    void update();
    void cleanup();
    
    void setupUVs();
};

#endif
