#pragma once
#include "actor.h"

using namespace bean_engine::bean_actors;
class enemy final : public actor {
public:
    enemy() = default;
    explicit enemy(const bean_engine::bean_math::transform& transform, const std::shared_ptr<bean_engine::bean_renderer::model> &model) noexcept {
        actor(transform, model);
    }

    void update(float dt) override;
private:
};
