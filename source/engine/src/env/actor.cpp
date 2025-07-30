#include "env/actor.h"


namespace bean_engine::bean_actors {
    void actor::update(float deltaTime) {
        m_transform.position += m_velocity * deltaTime;
    }

    void actor::draw(const bean_renderer::renderModule& renderer) const {
        m_model->draw(renderer, m_transform);
    }


}
