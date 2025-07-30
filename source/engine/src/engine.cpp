#include "engine.h"

#include <iostream>

namespace bean_engine {

    [[nodiscard]] engine& getEngine() {
        static engine engine;
        return engine;
    }

    engine::engine() {
        m_audio = std::make_unique<bean_audio::audioModule>();
        m_input = std::make_unique<bean_input::inputModule>();
        m_time = bean_core::time();
    }
    void engine::assignWindowProperties(const std::string &gameName, const uint32_t &width, const uint32_t &height) {
        if (m_renderer != nullptr) {
            throw std::runtime_error("Attempted reassignment of window properties.");
        }
        m_renderer = std::make_unique<bean_renderer::renderModule>(gameName, width, height);
    }


    void engine::update() const {
        if (m_renderer == nullptr) {
            throw std::runtime_error("Renderer window properties not assigned within engine.");
        }
    }

    void engine::kill() {
        m_audio->kill();
    }



}