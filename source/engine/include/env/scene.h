#pragma once
#include <vector>
#include <memory>
#include <string>
#include <list>


#include "renderer/core.h"
namespace bean_engine {
    class game;  // Forward declaration
}


namespace bean_engine::bean_actors {


    class actor;
    class scene {
    public:
        explicit scene(game* game) {
            m_game = game;
        }

        /**
        * Update all actors in the scene.
        * @param dt Deltatime.
        */
        void update(float dt);

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

        void removeAllActors();

        [[nodiscard]] actor* getActorByName(const std::string& name) const;

        template<typename T = actor>
        [[nodiscard]] std::vector<T*> getActorsByTag(const std::string& tag) const;
        game* getGame() const {
            return m_game;
        }
    protected:
        game* m_game = nullptr;
        std::list<std::unique_ptr<actor>> m_actors;
    };
}

#include "scene_impl.h"