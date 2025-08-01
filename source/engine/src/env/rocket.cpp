#include "env/rocket.h"
#include <iostream>
#include "engine.h"
#include "env/scene.h"
namespace bean_engine::bean_actors {
    void rocket::update(float dt) noexcept {

        const bean_math::vector2<float> force = bean_math::vector2<float>(1, 0).rotate(m_transform.rotation) * speed;
        m_velocity = force;

        auto const windowSize = getEngine().getRenderer().getDimensions();
        m_transform.position.x = bean_math::wrap(m_transform.position.x, 0.0f, static_cast<float>(windowSize.x));
        m_transform.position.y = bean_math::wrap(m_transform.position.y, 0.0f, static_cast<float>(windowSize.y));

        actor::update(dt);
    }
    void rocket::onCollision(actor *other) {
        if (other->m_tag != m_tag && other->m_tag != "player") {
            destroyed = true;
        }
    }

}