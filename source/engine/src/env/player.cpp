#include "env/player.h"

#include <iostream>
#include <oneapi/tbb/task_group.h>

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

    // 🔥 Laser auto-fire logic
    if (laserPersistTimer > 0.0f) {
        laserPersistTimer -= dt;

        std::vector<bean_math::vector2<float>> rocketShape = {
            { 3, 0 },
            { -3, -2 },
            { -3, 2 },
            { 3, 0 },
            { -3, -1 },
            { -3, 1 },
            { 3, 0 },
            { -3, 0 },
            { -3, -1 }
        };

        auto model = std::make_shared<bean_renderer::model>(
            rocketShape,
            bean_math::color4(255, 100, 100, 255)
        );

        bean_math::transform trans{
            m_transform.position,
            m_transform.rotation,
            0.5f
        };

        auto rocket = std::make_unique<bean_actors::rocket>(trans, model);
        rocket->lifespan = 3.5f;
        m_scene->addActor(std::move(rocket));
    } else {
        laserTimer -= dt;
    }

    std::cout << laserTimer << std::endl;

    if (getEngine().getInput().getKeyDown(SDL_SCANCODE_F) && laserTimer <= 0.0f) {
        laserTimer = laserDelay;
        laserPersistTimer = laserPersistLength;
    }

    fireTimer -= dt;

    if (getEngine().getInput().getKeyDown(SDL_SCANCODE_SPACE) && fireTimer <= 0.0f) {
        fireTimer = delay;
        std::vector<bean_math::vector2<float>> rocketShape = {
            { 3, 0 },
            { -3, -2 },
            { -3, 2 },
            { 3, 0 },
            { -3, -1 },
            { -3, 1 },
            { 3, 0 },
            { -3, 0 },
            { -3, -1 }
        };

        auto model = std::make_shared<bean_renderer::model>(
            rocketShape,
            bean_math::color4(255, 100, 100, 255)
        );

        bean_math::transform trans{
            m_transform.position,
            m_transform.rotation,
            1.5f
        };

        auto rocket = std::make_unique<bean_actors::rocket>(trans, model);
        rocket->lifespan = 1.25f;
        m_scene->addActor(std::move(rocket));
    }

    engineThrust -= dt;
    if (engineThrust <= 0.0f) {
        engineThrust = delayEngineThrust;
        bean_renderer::particle part;
        part.position = m_transform.position;
        part.velocity = this->m_velocity - bean_math::random::getReal(-5.0f, 5.0f);
        part.color = bean_math::color4(255, 255, 0);
        part.lifetime = 2.0f;
        getEngine().getPS().addParticle(part);
    }

    actor::update(dt);
}


    void player::onCollision(actor *other) {
        if (other->m_tag == "enemy") {
            destroyed = true;

            dynamic_cast<spaceGame*>(m_scene->getGame())->onPlrDeath();
        }
        if (other->m_tag == "droppedreseter") {
            switch (bean_math::random::getInt(0, 3)) {
                case 0: {
                    m_scene->getGame()->addPoints(bean_math::random::getInt(1, 100));
                }
                    case 1: {
                    m_scene->getGame()->increaseMultiplier();
                }
                    case 2: {
                    m_scene->getGame()->increaseMultiplier();
                }
                    default: {
                    fireTimer = 0.0f;
                    laserTimer = 0.0f;
                }
            }
        }
    }

}
