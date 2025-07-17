#pragma once
#include <vector>

#include "math/colors/color4.h"
#include "math/vectors/vector2.h"
#include "renderer/core.h"

namespace bean_engine::bean_renderer {
    class model {
        public:
        model(const std::vector<bean_math::vector2<float>>& vertices, const std::vector<bean_math::color4>& colors);
        model(const std::vector<bean_math::vector2<float>>& vertices, const bean_math::color4& color);
        void draw(const renderModule& renderer) const;

    private:
        std::vector<bean_math::vector2<float>> m_vertices;
        std::vector<bean_math::color4> m_colors;
    };
}
