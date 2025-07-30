#pragma once
#include "engine.h"
#include "env/player.h"

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

    for (size_t i = 0; i < 10; i++) {
        bean_math::transform trans{bean_math::vector2<float>()};
        auto plr = std::make_unique<bean_actors::player>(trans, model);
        m_scene->addActor(std::move(plr));
    }

}

inline void spaceGame::update() {
    m_scene->update(getEngine().getTimeModule().getDeltaTime());
}

inline void spaceGame::kill() {

}

inline void spaceGame::draw() {

}



inline int run() {
    bean_engine::engine& engine = bean_engine::getEngine();
    engine.assignWindowProperties("Space Game", 800, 800);
    auto game = std::make_unique<spaceGame>();
    game->init();
    bool quit = false;
    while (!quit) {
        quit = getEngine().getRenderer().tryExit();
        game->update();
        game->draw();
    }

    game->kill();
    return 0;
}
