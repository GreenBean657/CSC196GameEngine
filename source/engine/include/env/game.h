#pragma once
#include <memory>

#include "scene.h"

namespace bean_engine {
    class game {
        public:
        virtual ~game() = default;

        game() = default;

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void kill() = 0;
        virtual void draw() = 0;


    protected:
        int m_score = 0;
        int m_lives = 3;

        std::unique_ptr<bean_actors::scene> m_scene;
    };
}
