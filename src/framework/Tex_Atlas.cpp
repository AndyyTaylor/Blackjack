// Copyright 2017 Andy Taylor

#include "framework/Tex_Atlas.h"

#include <iostream>

namespace Tex_Atlas {
    const int CARD_WIDTH = 73;
    const int CARD_HEIGHT = 98;
    int TOTAL_WIDTH, TOTAL_HEIGHT;
    
    void setTotalDimensions(int _WIDTH, int _HEIGHT) {
        TOTAL_WIDTH = _WIDTH;
        TOTAL_HEIGHT = _HEIGHT;
    }

    glm::vec2 mapUVs(int x, int y, float ux, float uy) {
        return glm::vec2((x * CARD_WIDTH)  / static_cast<float>(TOTAL_WIDTH) + ux * (static_cast<float>(CARD_WIDTH) / TOTAL_WIDTH)
                       , (y * CARD_HEIGHT) / static_cast<float>(TOTAL_HEIGHT) + uy * (static_cast<float>(CARD_HEIGHT) / TOTAL_HEIGHT));
    }
};  // namespace Tex_Atlas

