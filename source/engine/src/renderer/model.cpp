#include "renderer/model.h"
#include "renderer/core.h"

namespace bean_engine::bean_renderer {

    model::model(const std::vector<bean_math::vector2<float> > &points, const bean_math::color4 &color4) {
        m_points = points;
        m_color = color4;
    }

    /**
     * @brief Draw the object based on specified position, rotation, and scale.
     * @param renderer Game renderer object.
     * @param position Vector2 position.
     * @param rotation Angle in radians.
     * @param scale Scale.
     */
    void model::draw(const renderModule& renderer, const bean_math::vector2<float>& position, const float rotation = 0.0f, const float scale = 1.0f) const {
        if (m_points.empty()) return;

        renderer.setDrawColor(m_color);

        for (size_t i = 0; i < m_points.size() - 1; ++i) {
            const auto p1 = (m_points[i].rotate(rotation) * scale) + position;
            const auto p2 = (m_points[(i + 1)].rotate(rotation) * scale) + position;

            renderer.drawLine(p1, p2);

        }
    }

    /**
     * @brief Draw the object based on a specified rotation.
     * @param renderer Game renderer object.
     * @param transform Transform object.
     */
    void model::draw(const renderModule& renderer, const bean_math::transform& transform) const {
        model::draw(renderer, transform.position, transform.rotation, transform.scale);

    }

}