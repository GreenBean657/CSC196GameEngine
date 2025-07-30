#pragma once
#include "vector2.h"

namespace bean_engine::bean_math {
    struct transform {
        vector2<float> position = vector2<float>(0, 0);
        float rotation = 0.0f;
        float scale = 1.0f;

        transform() = default;
        transform(const vector2<float>& position, const float rotation = 0.0f, const float scale = 1.0f) {
            this->position = position;
            this->rotation = rotation;
            this->scale = scale;
        }
    };
}
