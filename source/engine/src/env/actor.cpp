#include "env/actor.h"


namespace bean_engine::bean_actors {
    void actor::update(const float deltaTime) {
        m_transform.position += m_velocity * deltaTime;
        m_velocity *= (1.0f / (1.0f + damping * deltaTime));
    }

    void actor::draw(const bean_renderer::renderModule& renderer) const {
        m_model->draw(renderer, m_transform);
    }


}
