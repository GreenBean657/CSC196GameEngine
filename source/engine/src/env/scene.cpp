#include "env/scene.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "env/actor.h"
#include "renderer/core.h"

using namespace bean_engine::bean_actors;

void scene::draw(const bean_renderer::renderModule &renderer) const {
    for (const auto &actor : m_actors) {
        actor->draw(renderer);
    }
}

void scene::update(const float dt) {
    for (const auto &actor : m_actors) {
        actor->update(dt);
    }

    for (auto inter = m_actors.rbegin(); inter != m_actors.rend(); ) {
        if ((*inter)->destroyed) {
            // Erase using forward iterator, then convert back to reverse iterator
            inter = std::list<std::unique_ptr<actor>>::reverse_iterator(
                m_actors.erase(std::next(inter).base())
            );
        } else {
            ++inter;
        }
    }

    for (auto& actorA : m_actors) {
        for (auto& actorB : m_actors) {
            if ((actorA == actorB) || actorA->destroyed || actorB->destroyed) continue;
            float distance = (actorA->getTransform().position - actorB->getTransform().position).length();

            if (distance <= (actorA->getRadius() + actorB->getRadius())) {
                //Collision
                actorA->onCollision(actorB.get());
                actorB->onCollision(actorA.get());
            }
        }
    }

}


void scene::addActor(std::unique_ptr<actor> actor) {
    if (actor) {
        actor->m_scene = this;
        m_actors.push_back(std::move(actor));
    }
}

void scene::removeAllActors() {
    m_actors.clear();
}

actor* scene::getActorByName(const std::string& name) const {
    for (const auto &actor : m_actors) {
        if (actor->m_name == name) {
            return actor.get();
        }
    }
    return nullptr;
}


