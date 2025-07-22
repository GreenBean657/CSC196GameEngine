#pragma once
#include "audio/core.h"
#include "input/core.h"
#include "renderer/core.h"

namespace bean_engine {
    class Engine {
        public:
        explicit Engine(const std::string& gameName = "My Application", const uint32_t& width = 600, const uint32_t& height = 600) {
            m_renderer = new bean_renderer::renderModule(gameName, width, height);
            m_audio = new bean_audio::audioModule();
            m_input = new bean_input::inputModule();
        }





        ~Engine() {
            delete m_input;
            delete m_audio;
            delete m_renderer;
        }
        private:
            bean_renderer::renderModule *m_renderer = nullptr;
            bean_audio::audioModule *m_audio = nullptr;
            bean_input::inputModule *m_input = nullptr;
    };
}
