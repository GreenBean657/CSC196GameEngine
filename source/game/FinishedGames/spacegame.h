#pragma once
#include "env/game.h"
#include "renderer/text.h"

namespace bean_game::game_data {

    inline std::vector<bean_engine::bean_math::vector2<float>> lootLook{
    { -1, -1 },
    { 1, -1 },
    { 1, 1 },
    { -1, 1 },
    { -1, -1 }
        };


    inline std::vector<bean_engine::bean_math::vector2<float>> plrLook{
    { 3, 0 },
    { -2, -2 },
    { -1, -1 },
    { 0, 0 },
    { -1, 1 },
    { -2, 2 },
    { 3, 0 },
    };

    inline std::vector<bean_engine::bean_math::vector2<float>> enemyLook{
        { 3, 0 },
        { -3, -2 },
        { -3, 2 },
        { 3, 0 },
        { -3, -1 },
        { -3, 1 },
        { 3, 0 },
        { -3, 0 },
        { -3, -1 },
        { -4, -1 },
        { -4, 1 },
        { -3, 1 },
        { -3, 0 },
        { -4, 0 },
        { -3, -1 },
        { -4, -1 },
        { -3, 0 },
        { -4, 1 },
        { -3, 1 },
        { -4, 0 },
        };

}


class spaceGame final : public bean_engine::game {
    public:

    enum gameState {
        initialize,
        title,
        startGame,
        startRound,
        game,
        playerDead,
        gameOver
    };

    void init() override;
    void update(float dt) override;
    void kill() override;
    void draw() override;

    void onPlrDeath();

protected:
    float m_enemySpawnTimer = 0;

    bool loadedSound = false;
    float m_deathDelay = 4.0f;
    float m_stateTimer = m_deathDelay;
    gameState m_gameState = initialize;

    std::shared_ptr<bean_text::Font> m_titleFont = nullptr;
    std::shared_ptr<bean_text::Font> m_textFont = nullptr;

    std::unique_ptr<bean_text::Text> m_titleText;
    std::unique_ptr<bean_text::Text> m_titleText2;
    std::unique_ptr<bean_text::Text> m_scoreText;
    std::unique_ptr<bean_text::Text> m_livesText;
    std::unique_ptr<bean_text::Text> m_highScoreText;
};

#include "spacegame.hpp"