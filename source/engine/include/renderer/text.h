#pragma once
#include <memory>

#include "font.h"
#include "renderer/core.h"
#include "renderer/model.h"
struct SDL_Texture;
using namespace bean_engine;
namespace bean_engine::bean_text {
    class Text {
    public:
        Text() = default;

        explicit Text(const std::shared_ptr<Font>& font) {
            m_font = font;
        }

        ~Text();

        bool Create(const bean_renderer::renderModule & renderer, const std::string& text, const bean_engine::bean_math::color4);
        void Draw(const bean_renderer::renderModule &renderer, bean_math::vector2<float> position) const;


    private:
        std::shared_ptr<Font> m_font = nullptr;
        SDL_Texture* m_texture = nullptr;
    };
}