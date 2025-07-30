#include "env/scene.h"
#include "env/actor.h"
#include "renderer/core.h"

using namespace bean_engine::bean_actors;

void scene::draw(const bean_renderer::renderModule &renderer) const {
    for (const auto &actor : m_actors) {
        actor->draw(renderer);
    }
}

void scene::update(const float dt) const {
    for (const auto &actor : m_actors) {
        actor->update(dt);
    }
}


void scene::addActor(std::unique_ptr<actor> actor) {
    actor->m_scene = this;
    m_actors.push_back(std::move(actor));
}

actor* scene::getActorByName(const std::string& name) const {
    for (const auto &actor : m_actors) {
        if (actor->m_name == name) {
            return actor.get();
        }
    }
    return nullptr;
}


