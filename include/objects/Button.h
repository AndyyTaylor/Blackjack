// Copyright 2017 Andy Taylor

#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "objects/Object.h"

class Button : public Object {
 private:
    bool hover, new_hover;
    
 public:
    std::string file, hover_file;
    float width, height;
    int id;
    
    Button(float _x, float _y, float _z, int _id, std::string _file, std::string hover_file);
    
    void render();
    void update();
    void cleanup();
    
    void setHover(bool _hover);
    
    void setupUVs();
};

#endif
