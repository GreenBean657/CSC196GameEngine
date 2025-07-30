#pragma once
#include "engine.h"
#include "env/player.h"
#include "math/core/random.h"

using namespace bean_engine;
inline void spaceGame::init() {

    m_scene = std::make_unique<bean_actors::scene>();

    std::vector<bean_math::vector2<float>> position{
        {-5, -5},
        {5, -5},
        {5, 5},
        {-5, 5},
        {-5, -5}
    };

    auto model = std::make_shared<bean_renderer::model>(position, bean_math::color4(255, 255, 255, 255));

    bean_math::transform trans{
        {
            static_cast<float>(400),
            static_cast<float>(400),
        },
        0.0f,
        1.0};
    auto plr = std::make_unique<bean_actors::player>(trans, model);
    m_scene->addActor(std::move(plr));


}

inline void spaceGame::update() {
    m_scene->update(getEngine().getTimeModule().getDeltaTime());
}

inline void spaceGame::kill() {

}

inline void spaceGame::draw() {
    m_scene->draw(getEngine().getRenderer());
}



inline int run() {
    getEngine().assignWindowProperties("Space Game", 800, 800);
    auto game = std::make_unique<spaceGame>();
    game->init();
    bool quit = false;
    while (!quit) {
        getEngine().getRenderer().setDrawColor(bean_math::color4(0, 0, 0, 255));
        getEngine().getRenderer().clear();
        getEngine().getTimeModule().tick();
        quit = getEngine().getRenderer().tryExit();
        if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;
        getEngine().update();
        game->update();
        game->draw();
        getEngine().getInput().tick();
        getEngine().getRenderer().present();
    }

    return 0;
}
