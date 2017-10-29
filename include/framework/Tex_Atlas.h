// Copyright 2017 Andy Taylor

#ifndef TEX_ATLAS_INCLUDED
#define TEX_ATLAS_INCLUDED

#include "framework/Glm_common.h"

namespace Tex_Atlas {
    void setTotalDimensions(int _WIDTH, int _HEIGHT);
    
    glm::vec2 mapUVs(int x, int y, float ux, float uy);
};

#endif
