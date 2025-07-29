#pragma once
#include <ctime>

#include "input/core.h"
#include "math/vectors/vector3.h"
#include "renderer/core.h"
#include "renderer/model.h"
#include "time/time.h"
using namespace bean_engine;
inline int demo() {

    bean_renderer::renderModule renderer;
    bean_engine::bean_core::Time time;
    bean_input::inputModule input;
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

    const bean_renderer::model model(vertices, bean_math::color4(255, 255, 255));

    while (!quit) {
        quit = renderer.tryExit();

        renderer.setDrawColor(bean_math::color4(0, 0, 0, 255));
        renderer.clear();
        model.Draw(renderer, input.getMousePosition(), time.getTime(), 10.0f);
        renderer.present();
        input.tick();
        time.tick();

    }
    return 0;
}