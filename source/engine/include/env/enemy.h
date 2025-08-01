#pragma once
#include "actor.h"

namespace bean_engine::bean_actors {
    class enemy final : public actor {
    public:
        enemy() = default;
        explicit enemy(const bean_math::transform& transform, const std::shared_ptr<bean_renderer::model> &model) noexcept : actor(transform, model) {
            m_name = "enemy";
            m_tag = "enemy";
        };

        void onCollision(actor* other) override;
        void update(float dt) override;
    private:
    };
}