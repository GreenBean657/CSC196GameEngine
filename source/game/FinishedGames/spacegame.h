#pragma once
#include "env/game.h"
#include "renderer/text.h"

namespace bean_game::game_data {
    inline std::vector<bean_engine::bean_math::vector2<float>> plrLook{
            {-5, -5},
            {5, -5},
            {5, 5},
            {-5, 5},
            {-5, -5}
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

protected:
    float m_enemySpawnTimer = 0;
    gameState m_gameState = initialize;

    std::shared_ptr<bean_text::Font> m_titleFont = nullptr;
    std::shared_ptr<bean_text::Font> m_textFont = nullptr;
};

#include "spacegame.hpp"