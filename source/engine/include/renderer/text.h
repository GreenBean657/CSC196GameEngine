#pragma once
#include "font.h"
#include "renderer/core.h"
#include "renderer/model.h"
struct SDL_Texture;
using namespace bean_engine;
namespace bean_engine::bean_text {
    class Text {
    public:
        Text() = default;

        explicit Text(bean_engine::bean_text::Font* font) {
            m_font = font;
        }

        ~Text();

        bool Create(bean_renderer::renderModule & renderer, const std::string& text, const bean_engine::bean_math::color4);
        void Draw(bean_renderer::renderModule &renderer, bean_math::vector2<float> position);


    private:
        Font* m_font = nullptr;
        SDL_Texture* m_texture = nullptr;
    };
}