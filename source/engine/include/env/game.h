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
        std::unique_ptr<bean_actors::scene> m_scene;
    };
}
