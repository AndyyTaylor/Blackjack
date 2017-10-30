// Copyright 2017 Andy Taylor

#ifndef IMAGE_OVERLAY_H
#define IMAGE_OVERLAY_H

#include "objects/Object.h"

class ImageOverlay : public Object {
 private:
    
 public:
    ImageOverlay(float _x, float _y, float _z, std::string file);
    
    void render();
    void update();
    void cleanup();
    
    void setupUVs();
};

#endif
