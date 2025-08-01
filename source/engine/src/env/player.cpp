#include "env/player.h"

#include <iostream>

#include "input/core.h"
#include "engine.h"
#include "env/actor.h"
#include "../../../game/FinishedGames/spacegame.hpp"
#include "env/rocket.h"

namespace bean_engine::bean_actors {
    void player::update(const float dt) {
        constexpr float speed = 50.0f;
        float rotation = 0.0f;
        constexpr float rotationRate = 5.0f;



        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) rotation -= 1.0f;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) rotation += 1.0f;
        m_transform.rotation += (rotation * rotationRate) * dt;

        float thrust = 0.0f;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) thrust += 1.0f;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) thrust -= 1.0f;

        const bean_math::vector2<float> direction{1, 0};
        const bean_math::vector2<float> force = direction.rotate(m_transform.rotation) * thrust * speed;
        m_velocity += force * dt;

        auto const windowSize = getEngine().getRenderer().getDimensions();
        m_transform.position.x = bean_math::wrap(m_transform.position.x, 0.0f, static_cast<float>(windowSize.x));
        m_transform.position.y = bean_math::wrap(m_transform.position.y, 0.0f, static_cast<float>(windowSize.y));

        fireTimer -= dt;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_F) && fireTimer <= 0.0f) {
            fireTimer = delay;
            // Create a dedicated model for rockets instead of reusing plrLook
            std::vector<bean_math::vector2<float>> rocketShape = {
                {0, 4},   // Rocket tip
                {-2, -2}, // Left corner
                {2, -2},  // Right corner
                {0, 4}    // Back to tip
            };

            auto model = std::make_shared<bean_renderer::model>(
                rocketShape,
                bean_math::color4(255, 100, 100, 255)
            );

            bean_math::transform trans{
                m_transform.position,
                m_transform.rotation,
                1.0f
            };

            auto rocket = std::make_unique<bean_actors::rocket>(trans, model);

            rocket->lifespan = 1.5f;
            m_scene->addActor(std::move(rocket));
        }

        actor::update(dt);
    }

    void player::onCollision(actor *other) {
        return;
    }

}
