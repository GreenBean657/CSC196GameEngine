#include "env/enemy.h"
#include <iostream>
#include "engine.h"
namespace bean_engine::bean_actors {
    void enemy::update(const float dt) {
        constexpr float speed = 200.0f;
        bean_math::vector2<float> direction{1, 0};

        actor* player = m_scene->getActorByName("player");
        if (player != nullptr) {
            direction = player->getTransform().position - this->getTransform().position;
            direction = direction.normalized();
            m_transform.rotation = direction.angle();
        }

        const bean_math::vector2<float> force = bean_math::vector2<float>(1, 0).rotate(m_transform.rotation) * speed;
        m_velocity += force * dt;

        auto const windowSize = getEngine().getRenderer().getDimensions();
        m_transform.position.x = bean_math::wrap(m_transform.position.x, 0.0f, static_cast<float>(windowSize.x));
        m_transform.position.y = bean_math::wrap(m_transform.position.y, 0.0f, static_cast<float>(windowSize.y));

        actor::update(dt);
    }

}