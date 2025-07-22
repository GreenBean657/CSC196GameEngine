#pragma once

#include <bits/ostream.tcc>

#include "../engine/include/math/vectors/vector2.h"
#include "input/core.h"
#include "renderer/core.h"

#include <SDL3/SDL.h>

#include "shapedrawer.h"
#include "renderer/model.h"
#include <iostream>

#include "renderer/font.h"
#include "renderer/text.h"
using namespace bean_engine;
inline int drawShape() {

    bean_renderer::renderModule renderer;
    bean_input::inputModule input;
    bool quit = false;

    auto* font = new bean_text::Font();
    font->load("data-unifon.ttf", 20);

    auto* text = new bean_text::Text(font);
    text->Create(renderer, "hello world", bean_engine::bean_math::color4(255, 255, 255, 255));
    while (!quit) {
        quit = renderer.tryExit();
        if (input.getKeyDown(SDL_SCANCODE_Q)) {
            quit = true;
        }
        std::vector<bean_math::vector2<float>> vertices;
        vertices.emplace_back(160, 220);
        vertices.emplace_back(220, 180);
        vertices.emplace_back(280, 220);
        vertices.emplace_back(340, 180);
        vertices.emplace_back(380, 190);
        vertices.emplace_back(390, 240);
        vertices.emplace_back(380, 280);
        vertices.emplace_back(300, 320);
        vertices.emplace_back(340, 260);
        vertices.emplace_back(290, 255);
        vertices.emplace_back(240, 320);
        vertices.emplace_back(200, 270);
        vertices.emplace_back(170, 270);
        vertices.emplace_back(vertices[0]);
        bean_renderer::model model(vertices, bean_math::color4(0, 255, 0, 0));
        model.draw(renderer);
        text->Draw(renderer, bean_math::vector2<float>(2, 4));
        renderer.present();
        input.tick();
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}