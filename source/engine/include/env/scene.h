#pragma once
#include <vector>
#include <memory>
#include <string>
#include "renderer/core.h"

namespace bean_engine::bean_actors {

    class actor;

    class scene {
    public:
        scene() = default;

        /**
        * Update all actors in the scene.
        * @param dt Deltatime.
        */
        void update(float dt) const;

        /**
        * @brief Draw all the actors to the screen.
        * @param renderer Renderer to draw on.
        */
        void draw(const bean_renderer::renderModule& renderer) const;

        /**
         * Add an actor to the scene.
         * @param actor Actor to add.
         */
        void addActor(std::unique_ptr<actor> actor);

        actor* getActorByName(const std::string& name) const;
    protected:
        std::vector<std::unique_ptr<actor>> m_actors;
    };
}