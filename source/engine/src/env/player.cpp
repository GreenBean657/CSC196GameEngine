#include "env/player.h"
#include "input/core.h"
#include "engine.h"
#include "env/actor.h"

namespace bean_engine::bean_actors {
    void player::update(const float dt) {
        bean_math::vector2<float> direction;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) direction.y -= 1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) direction.y += 1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) direction.x -= 1;
        if (getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) direction.x += 1;

        if (direction.lengthSqr() > 0) {
            float speed = 1.0f;
            direction = direction.normalized();
            m_transform.position += (direction * speed) * dt;
        }
    }
}