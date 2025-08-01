#pragma once
#include <vector>

#include "math/colors/color4.h"
#include "math/vectors/vector2.h"
#include "renderer/core.h"
#include "math/vectors/transform.h"
namespace bean_engine::bean_renderer {
    class model {

        public:
        model(const std::vector<bean_math::vector2<float>>& points, const bean_math::color4& color4);

        void draw(const renderModule& renderer, const bean_math::vector2<float>& position, float rotation, float scale) const;
        void draw(const renderModule& renderer, const bean_math::transform& transform) const;
        ~model() = default;

        [[nodiscard]] float getRadius() const { return m_radius; }


    private:
        float m_radius = 0;
        void calculateRadius();
        std::vector<bean_math::vector2<float>> m_points;
        bean_math::color4 m_color = bean_math::random_color4();
    };
}
