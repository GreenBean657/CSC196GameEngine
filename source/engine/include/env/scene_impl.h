#pragma once
#include "env/scene.h"
#include "env/actor.h"

namespace bean_engine::bean_actors {
    template<typename T>
    inline std::vector<T*> scene::getActorsByTag(const std::string& tag) const {
        std::vector<T*> result;
        for (const auto& actor : m_actors) {
            if (actor->m_tag == tag) {
                T* object = dynamic_cast<T*>(actor.get());
                if (object) {
                    result.push_back(object);
                }
            }
        }
        return result;
    }
}