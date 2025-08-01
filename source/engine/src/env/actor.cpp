#include "env/actor.h"


namespace bean_engine::bean_actors {
    void actor::update(const float deltaTime) {

        if (destroyed) return;

        if (lifespan != -1.0f) {
            lifespan -= deltaTime;
            if (lifespan <= 0.0f) destroyed = true;
        }
        m_transform.position += m_velocity * deltaTime;
        m_velocity *= (1.0f / (1.0f + damping * deltaTime));
    }

    void actor::draw(const bean_renderer::renderModule& renderer) const {
        if (destroyed) return;
        m_model->draw(renderer, m_transform);
    }


}
