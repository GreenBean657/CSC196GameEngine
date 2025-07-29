#include "renderer/model.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "renderer/core.h"
#include "math/colors/color4.h"
namespace bean_engine::bean_renderer {

    model::model(const std::vector<bean_math::vector2<float>>& vertices, const bean_math::color4& color) {
        m_vertices = std::vector<bean_math::vector2<float>>(vertices);
        m_colors = bean_math::color4(color);
    }
    void model::draw(const renderModule &renderer, const bean_math::vector2<float> &position, float rotation, float scale) const {
        if (m_vertices.empty()) return;

        renderer.setDrawColor(m_colors);
    }


}