#include "renderer/model.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "renderer/core.h"
namespace bean_engine::bean_renderer {

    model::model(const std::vector<bean_math::vector2<float> > &vertices, const std::vector<bean_math::color4> &colors) {
        for (size_t i = 0; i < vertices.size(); i++) {
            m_colors.push_back(colors[i]);
        }
        for (size_t i = 0; i < vertices.size(); i++) {
            m_vertices.push_back(vertices[i]);
        }
    }

    model::model(const std::vector<bean_math::vector2<float> > &vertices, const bean_math::color4 &color) {
        for (size_t i = 0; i < vertices.size(); i++) {
            m_colors.push_back(bean_math::color4(color));
        }
        for (size_t i = 0; i < vertices.size(); i++) {
            m_vertices.push_back(vertices[i]);
        }
    }


    void model::draw(const renderModule& renderer) const {

        if (m_vertices.empty() || m_vertices.size() < 2) {
            std::cerr << "Failure Drawing Model, vertices size is less than 2" << std::endl;
            return;
        }

        for (size_t i = 0; i < (m_vertices.size() - 1); i++) {
            renderer.setDrawColor(m_colors[i]);
            renderer.drawLine(m_vertices[i], m_vertices[i + 1]);
        }
    }

}