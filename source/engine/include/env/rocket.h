#pragma once
#include "actor.h"
namespace bean_engine::bean_actors {
    class rocket : public actor {
        public:
        float speed = 200;

        rocket() = default;
        rocket(const bean_engine::bean_math::transform& transform, const std::shared_ptr<bean_engine::bean_renderer::model> &model) noexcept : actor(transform, model) {
            m_name = "rocket";
            m_tag = "rocket";
        };
        void onCollision(actor* other) override;
        void update(float dt) noexcept override;
    };
}