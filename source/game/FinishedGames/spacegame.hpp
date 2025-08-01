#pragma once
#include <iostream>

#include "engine.h"
#include "spacegame.h"
#include "env/player.h"
#include "math/core/random.h"
#include "env/enemy.h"
#include "env/firereset.h"
#include "io/core.h"


using namespace bean_engine;
inline void spaceGame::init() {

    if (!file_io::exists("score.txt")) {
        file_io::WriteTextFile("score.txt", "0");
    }

    m_scene = std::make_unique<bean_actors::scene>(this);
    bean_math::random::seed(657);

    m_titleFont = std::make_shared<bean_text::Font>();
    m_titleFont->load("CharmingAlphabet.otf", 60);
    m_textFont = std::make_shared<bean_text::Font>();
    m_textFont->load("CharmingAlphabet.otf", 24);

    m_titleText = std::make_unique<bean_text::Text>(m_titleFont);
    m_titleText2 = std::make_unique<bean_text::Text>(m_titleFont);
    m_highScoreText = std::make_unique<bean_text::Text>(m_textFont);
    m_scoreText = std::make_unique<bean_text::Text>(m_textFont);
    m_livesText = std::make_unique<bean_text::Text>(m_textFont);
}


inline void spaceGame::update(float dt) {
    if (!loadedSound) {
        loadedSound = getEngine().getAudio().addSound("1hmusic.mp3", "1hmusic");
        if (loadedSound) {
            getEngine().getAudio().playSound("1hmusic");
        }
    }
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

            m_scene->removeAllActors();

            auto model = std::make_shared<bean_renderer::model>(bean_game::game_data::plrLook, bean_math::color4(255, 255, 255, 255));
            bean_math::transform trans{
            {
                static_cast<float>(400),
                static_cast<float>(400),
            },
            0.0f,
            4.0};
            auto plr = std::make_unique<bean_actors::player>(trans, model);
            m_scene->addActor(std::move(plr));
            m_gameState = game;
            break;
        }
        case game: {
            m_enemySpawnTimer -= dt;
            if (m_enemySpawnTimer <= 0) {
                m_enemySpawnTimer = 4;
                if (bean_math::random::getBool() == true) {
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
                } else {
                    auto dims = getEngine().getRenderer().getDimensions();
                    bean_math::transform transEnemy {
                        {
                            static_cast<float>(bean_math::random::getInt(0, dims.x)),
                            static_cast<float>(bean_math::random::getInt(0, dims.y)),
                        },
                        0.0f,
                        3.0f
                        };
                    auto enemyModel = std::make_shared<bean_renderer::model>(
                     bean_game::game_data::lootLook,
                bean_math::color4(0, 255, 0)
);
                    auto enemy = std::make_unique<bean_actors::firereset>(transEnemy, enemyModel);
                    m_scene->addActor(std::move(enemy));
                }
            }
            break;
        }
        case playerDead: {
            m_scene->removeAllActors();
            m_stateTimer -= dt;
            if (m_stateTimer <= 0) {
                m_stateTimer = m_deathDelay;
                m_lives--;
                if (m_lives == 0) {
                    m_gameState = gameOver;
                } else {
                    m_gameState = startRound;
                }
            }
            break;
        }
        case gameOver: {
            m_stateTimer -= dt;
            if (m_stateTimer <= 0) {
                m_stateTimer = m_deathDelay;
                m_gameState = title;
            }
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
    if (m_score >= std::stoi(file_io::ReadTextFile("score.txt"))) {
        file_io::WriteTextFile("score.txt", std::to_string(m_score));
    }

    if (m_gameState == title) {
        m_titleText->Create(getEngine().getRenderer(), "Bean Shooter", bean_engine::bean_math::color4(255, 255, 255));
        m_titleText->Draw(getEngine().getRenderer(), bean_math::vector2<float>(300, 300));

        m_titleText2->Create(getEngine().getRenderer(), "Press SPACE to start!", bean_engine::bean_math::color4(255, 255, 255));
        m_titleText2->Draw(getEngine().getRenderer(), bean_math::vector2<float>(250, 400));
    }

    m_scoreText->Create(getEngine().getRenderer(), "Score :" + std::to_string(m_score), bean_math::color4(255, 255, 255));
    m_scoreText->Draw(getEngine().getRenderer(), bean_math::vector2<float>(0, 00));

    m_highScoreText->Create(getEngine().getRenderer(), "High Score :" + ((static_cast<std::string>(bean_engine::file_io::ReadTextFile("score.txt")))), bean_math::color4(255, 255, 255));
    m_highScoreText->Draw(getEngine().getRenderer(), bean_math::vector2<float>(0, 25));

    m_livesText->Create(getEngine().getRenderer(), "Lives :" + std::to_string(m_lives), bean_math::color4(255, 255, 255));
    m_livesText->Draw(getEngine().getRenderer(), bean_math::vector2<float>(0, 50));
    m_scene->draw(getEngine().getRenderer());
}

inline void spaceGame::onPlrDeath() {
    m_gameState = playerDead;
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

        // Update particle system
        getEngine().getPS().update(getEngine().getTimeModule().getDeltaTime());

        // In spacegame.hpp game loop, before getEngine().getRenderer().present():
        getEngine().getPS().draw(getEngine().getRenderer());

        getEngine().getRenderer().present();

    }

    return 0;
}


#include "env/scene_impl.h"