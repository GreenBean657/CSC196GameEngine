#pragma once
#include <memory>

#include "scene.h"

namespace bean_engine {
    class game {
        public:
        virtual ~game() = default;

        game() = default;

        virtual void init() = 0;
        virtual void update(float dt) = 0;
        virtual void kill() = 0;
        virtual void draw() = 0;

         void addPoints(const int numPoints) {
            m_score += numPoints;
        }
        [[nodiscard]] int getScore() const {
            return m_score;
        }

        [[nodiscard]] int getLives() const {
            return m_lives;
        }

        void setLives(const int lives) {
            m_lives = lives;
        }

    protected:
        int m_score = 0;
        int m_lives = 3;

        std::unique_ptr<bean_actors::scene> m_scene;
    };
}
