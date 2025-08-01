#include "env/rocket.h"
#include <iostream>
#include "engine.h"
#include "env/firereset.h"
namespace bean_engine::bean_actors {
    void firereset::update(float dt) noexcept {

        actor::update(dt);
    }
    void firereset::onCollision(actor *other) {
        if (other->m_tag == "player") {
            destroyed = true;
        }
    }

}