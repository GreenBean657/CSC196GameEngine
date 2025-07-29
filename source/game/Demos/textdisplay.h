#pragma once

#include <bits/ostream.tcc>

#include "../engine/include/math/vectors/vector2.h"
#include "input/core.h"
#include "renderer/core.h"

#include <SDL3/SDL.h>

#include "shapedrawer.h"
#include "renderer/model.h"
#include <iostream>

#define SIZE 600

#include "renderer/font.h"
#include "renderer/text.h"
using namespace bean_engine;
inline int drawText() {

    bean_renderer::renderModule renderer("Text Display", SIZE, SIZE);
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
        text->Draw(renderer, bean_math::vector2(static_cast<float>(SIZE)/2, static_cast<float>(SIZE)/2));
        renderer.present();
        input.tick();
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}