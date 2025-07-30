#include "renderer/text.h"
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>

using namespace bean_engine;

bean_text::Text::~Text() {
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
    }
}

bool bean_text::Text::Create(const bean_engine::bean_renderer::renderModule &renderer, const std::string &text, const bean_engine::bean_math::color4 c) {
    const SDL_Color color = {c.r, c.g, c.b, c.a};
    SDL_Surface* surface = TTF_RenderText_Solid(m_font->m_tffFont, text.c_str(), text.size(), color);
    if (surface == nullptr) {
        std::cout << "TTF_RenderText_Solid failed" << std::endl;
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
    if (m_texture == nullptr) {
        SDL_DestroySurface(surface);
        std::cout << "SDL_CreateTextureFromSurface failed" << std::endl;
        return false;
    }

    SDL_DestroySurface(surface);

    return true;
}

void bean_text::Text::Draw(const bean_engine::bean_renderer::renderModule &renderer, bean_engine::bean_math::vector2<float> position) const {
    float width, height;
    bool success = SDL_GetTextureSize(m_texture, &width, &height);
    assert(success);

    SDL_FRect rect{position.x, position.y, width, height};
    success = SDL_RenderTexture(renderer.m_renderer, m_texture, nullptr, &rect);
    assert(success);
}


