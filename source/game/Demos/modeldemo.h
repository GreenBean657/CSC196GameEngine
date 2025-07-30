#pragma once
#include <ctime>

#include "env/actor.h"
#include "input/core.h"
#include "math/vectors/vector3.h"
#include "renderer/core.h"
#include "renderer/model.h"
#include "time/time.h"
#include <memory>

#include "env/scene.h"
using namespace bean_engine;
inline int demo() {

    bean_renderer::renderModule renderer;
    bean_core::time time;
    auto input = std::make_unique<bean_input::inputModule>();

    auto quit = false;
    std::vector<bean_math::vector2<float>> vertices;
    vertices.emplace_back(16, 22);
    vertices.emplace_back(0, 0);
    vertices.emplace_back(28, 22);
    vertices.emplace_back(34, 18);
    vertices.emplace_back(38, 19);
    vertices.emplace_back(39, 24);
    vertices.emplace_back(38, 28);
    vertices.emplace_back(30, 32);
    vertices.emplace_back(34, 26);
    vertices.emplace_back(29, 25);
    vertices.emplace_back(24, 32);
    vertices.emplace_back(20, 27);
    vertices.emplace_back(17, 27);
    vertices.emplace_back(vertices[0]);

    std::shared_ptr<bean_renderer::model> model = std::make_shared<bean_renderer::model>(vertices, bean_math::color4(255, 255, 255));

    const bean_math::transform transform{bean_math::vector2<float>(0, 0), 180, 20};

    while (!quit) {
        quit = renderer.tryExit();

        bean_math::vector2<float> direction(0, 0);
        if (input->getKeyDown(SDL_SCANCODE_W)) direction.y = -1;
        if (input->getKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (input->getKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (input->getKeyDown(SDL_SCANCODE_D)) direction.x = 1;
        if (direction.lengthSqr() > 0) {
            constexpr float speed = 200.0f;
            direction = direction.normalized();
           // actor->getTransform().position += (direction * speed) * time.getDeltaTime();
        }

        //if (input->getKeyDown(SDL_SCANCODE_Q)) actor->getTransform().rotation -= bean_math::degToRad(90 * time.getDeltaTime());
        //if (input->getKeyDown(SDL_SCANCODE_E)) actor->getTransform().rotation += bean_math::degToRad(90 * time.getDeltaTime());
        renderer.setDrawColor(bean_math::color4(0, 0, 0, 255));
        renderer.clear();

        renderer.present();
        input->tick();
        time.tick();

    }

    renderer.kill();
    return 0;
}