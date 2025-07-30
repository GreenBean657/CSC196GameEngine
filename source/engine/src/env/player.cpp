#include "env/player.h"

#include <iostream>

#include "input/core.h"
#include "engine.h"
#include "env/actor.h"

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

        actor::update(dt);
    }
}