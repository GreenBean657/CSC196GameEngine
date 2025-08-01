#pragma once
#include "audio/core.h"
#include "input/core.h"
#include "renderer/core.h"
#include "time/time.h"
#include "renderer/particles.h"

using namespace bean_engine;
namespace bean_engine {

    class engine {
        public:
        explicit engine();

        void assignWindowProperties(const std::string& gameName = "My Application", const uint32_t& width = 600, const uint32_t& height = 600);

        void kill();

        void update() const;

        [[nodiscard]] bean_renderer::renderModule& getRenderer() const { return *m_renderer;};
        [[nodiscard]] bean_audio::audioModule& getAudio() const {return *m_audio;}
        [[nodiscard]] bean_input::inputModule& getInput() const {return *m_input;}
        [[nodiscard]] bean_renderer::particleSystem& getPS() const {return *m_particlesystem;}

        bean_core::time& getTimeModule() {return m_time;}

        private:
            bean_core::time m_time;
            std::unique_ptr<bean_renderer::renderModule> m_renderer = nullptr;
            std::unique_ptr<bean_audio::audioModule> m_audio;
            std::unique_ptr<bean_input::inputModule> m_input;
            std::unique_ptr<bean_renderer::particleSystem> m_particlesystem;
    };

    [[nodiscard]] engine& getEngine();

}
