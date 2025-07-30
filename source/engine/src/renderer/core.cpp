#include "renderer/core.h"

#include <iostream>
#include <stdexcept>
#include <SDL3_ttf/SDL_ttf.h>

namespace bean_engine::bean_renderer {

    void renderModule::kill() const {
        TTF_Quit();
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    renderModule::renderModule(const std::string &name, const int32_t &width, const int32_t &height) {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            throw std::runtime_error("Failed to initialize SDL3.");
        }
        if (!TTF_Init()) {
            throw std::runtime_error("Failed to initialize TTF.");
        }
        m_window = SDL_CreateWindow(name.c_str(), (width), (height), 0);
        if (m_window == nullptr) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return;
        }

        m_renderer = SDL_CreateRenderer(m_window, nullptr);
        if (m_renderer == nullptr) {
            std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
            kill();
            return;
        }
    }

    void renderModule::setDrawColor(bean_math::color4 color) const {
        SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    }

    void renderModule::setDrawColor(const bean_math::f_color4& color) const {
        SDL_SetRenderDrawColorFloat(m_renderer, color.r, color.g, color.b, color.a);
    }
    void renderModule::clear() const {
        SDL_RenderClear(m_renderer);
    }
    void renderModule::present() const {
        SDL_RenderPresent(m_renderer);
    }
    /**
     * @brief Detect if the user has requested a close window event.
     * @return TRUE = EXIT REQUESTED | FALSE = DO NOT EXIT
     */
    bool renderModule::tryExit() {
        SDL_Event polledEvent;
        while (SDL_PollEvent(&polledEvent)) {
            if (polledEvent.type == SDL_EVENT_QUIT) {
                return true; //Exit
            }
        }
        return false; //Stay
    }

    renderModule::~renderModule() {
        kill();
    }

    bean_math::vector2<int32_t > renderModule::getDimensions() const noexcept{
        return {m_width, m_height};
    }
}
