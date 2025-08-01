#pragma once
#include <iostream>

#include "engine.h"
#include "spacegame.h"
#include "env/player.h"
#include "math/core/random.h"
#include "env/enemy.h"


using namespace bean_engine;
inline void spaceGame::init() {


    m_scene = std::make_unique<bean_actors::scene>(this);
    bean_math::random::seed(657);

    m_titleFont = std::make_shared<bean_text::Font>();
    m_titleFont->load("CharmingAlphabet.otf", 24);
    m_textFont = std::make_shared<bean_text::Font>();
    m_textFont->load("BumpyRaceDemoRegular.ttf", 24);

}

inline void spaceGame::update(float dt) {
    switch (m_gameState) {
        case initialize: {
            m_gameState = title;
            break;
        }
        case title: {
            if (getEngine().getInput().getKeyPressed(SDL_SCANCODE_SPACE)) {
                m_gameState = startGame;
            }
            break;
        }

        case startGame: {
            m_score = 0;
            m_lives = 3;
            m_gameState = startRound;
            break;
        }

        case startRound: {
            auto model = std::make_shared<bean_renderer::model>(bean_game::game_data::plrLook, bean_math::color4(255, 255, 255, 255));
            bean_math::transform trans{
            {
                static_cast<float>(400),
                static_cast<float>(400),
            },
            0.0f,
            1.0};
            auto plr = std::make_unique<bean_actors::player>(trans, model);
            m_scene->addActor(std::move(plr));
            m_gameState = game;
            break;
        }
        case game: {
            m_enemySpawnTimer -= dt;
            if (m_enemySpawnTimer <= 0) {
                m_enemySpawnTimer = 4;
                auto dims = getEngine().getRenderer().getDimensions();
                bean_math::transform transEnemy {
                {
                    static_cast<float>(bean_math::random::getInt(0, dims.x)),
                    static_cast<float>(bean_math::random::getInt(0, dims.y)),
                },
                0.0f,
                3.0f
            };

                // Create a model from the look data first
                auto enemyModel = std::make_shared<bean_renderer::model>(
                    bean_game::game_data::enemyLook,
                    bean_math::color4(255, 255, 0, 255)
                );

                // Pass the model to the enemy constructor
                auto enemy = std::make_unique<bean_actors::enemy>(transEnemy, enemyModel);
                m_scene->addActor(std::move(enemy));
            }
            break;
        }
        case playerDead: {
            m_lives--;
            if (m_lives == 0) {
                m_gameState = gameOver;
            } else {
                m_gameState = startRound;
            }
            break;
        }
        case gameOver: {
            break;
        }
        default: {
            std::cerr << "Unrecognized game state: " << m_gameState << std::endl;
            break;
        }
    }

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
        game->update(getEngine().getTimeModule().getDeltaTime());
        game->draw();
        getEngine().getInput().tick();
        getEngine().getRenderer().present();
    }

    return 0;
}

#include "env/scene_impl.h"