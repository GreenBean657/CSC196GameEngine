#pragma once
#include <iostream>

#include "input/inputsystem.h"
#include "render/renderer.h"
#include "math/math.h"
#include "math/vector.h"


inline int InputPaint() {


    engine::Renderer renderer;

    bool succ = renderer.Initialize();
    if (!succ) {
        std::cerr << "Failed to initialize renderer :(" << std::endl;
        return 1;
    }

    succ = renderer.CreateWindow("Paint Util", 800, 800);
    if (!succ) {
        std::cerr << "Failed to create window :(" << std::endl;
        return 1;
    }


    std::vector<engine::math::FVec2> points;

    engine::InputSystem InputSystem;
    succ = InputSystem.Initialize();
    if (!succ) {
        std::cerr << "Failed to initialize input :(" << std::endl;
        return 1;
    }
    bool quit = false;
    while (!quit) {
        quit = renderer.tryExit();
        InputSystem.Tick();

        if (InputSystem.GetMouseButtonDown(engine::InputMouseButtons::M_BUTTON_LEFT)) {
            auto position = InputSystem.getMousePosition();

            if (points.empty() || ((position - points.back()).Length() > 10)) {
                points.push_back(position);
            }
        }
        if (points.size() > 2) {
            for (size_t i = 0; i < (points.size() - 1); i++) {
                renderer.setColor(engine::math::getRandomInt(255), engine::math::getRandomInt(255), engine::math::getRandomInt(255), 255);
                renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
            }
        }

        renderer.Present();
    }
    renderer.Kill();

    return 0;
}
