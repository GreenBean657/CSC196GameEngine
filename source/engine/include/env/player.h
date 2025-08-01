#pragma once
#include "env/actor.h"

namespace bean_engine::bean_actors {
    class player : public actor {

    public:
        player() = default;
        explicit player(const bean_engine::bean_math::transform& transform, const std::shared_ptr<bean_engine::bean_renderer::model> &model) noexcept : actor(transform, model) {
            m_name = "player";
            m_tag = "player";
        };

        void onCollision(actor* other) override;
        void update(float dt) override;
    private:
        float delay = 0.4f;
        float fireTimer = delay;

        float laserDelay = 2.5f;
        float laserPersistLength = 0.4f;
        float laserTimer = laserDelay;
        float laserPersistTimer = 0.0f;

        float delayEngineThrust = 0.01f;
        float engineThrust = delayEngineThrust;
    };
}
