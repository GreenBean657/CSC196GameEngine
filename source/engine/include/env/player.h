#pragma once
#include "actor.h"

namespace bean_engine::bean_actors {
    class player : public actor {
    public:
        player() = default;
        explicit player(const bean_engine::bean_math::transform& transform, const std::shared_ptr<bean_engine::bean_renderer::model> &model) noexcept : actor(transform, model) {};

        void update(float dt) override;
    private:
    };
}
