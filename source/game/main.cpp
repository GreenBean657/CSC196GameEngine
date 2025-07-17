#include <iostream>
#include <bits/ostream.tcc>

#include "../engine/include/math/vectors/vector2.h"
#include "input/core.h"
#include "renderer/core.h"

#include <SDL3/SDL.h>

#include "renderer/model.h"
using namespace bean_engine;
int main() {
    //bean_math::vector2<float> vec = bean_math::vector2<float>(1, 1);
    bean_renderer::renderModule renderer;
    bean_input::inputModule input;
    bool quit = false;
    while (!quit) {
        quit = renderer.tryExit();
        if (input.getKeyDown(SDL_SCANCODE_Q)) {
            quit = true;
        }
        //renderer.setDrawColor(bean_math::color4(255, 0, 0, 0));
        std::vector<bean_math::vector2<float>> vertices;
        vertices.emplace_back(0, 0);
        vertices.emplace_back(100, 0);
        vertices.emplace_back(0, 100);
        vertices.emplace_back(100, 200);
        bean_renderer::model model(vertices, bean_math::color4(255, 0, 0, 0));
        model.draw(renderer);
        //renderer.drawPoint(bean_engine::bean_math::vector2<float>(2, 5));
        //renderer.drawLine(bean_engine::bean_math::vector2<float>(2, 8), bean_engine::bean_math::vector2<float>(82, 28));
        renderer.present();
        input.tick();
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
