#pragma once
#include <SDL3/SDL_render.h>

#include "core_extended.h"
#include "math/vectors/vector2.h"

// renderModule_impl.tpp

namespace bean_engine::bean_renderer {

    template<typename T>
    void renderModule::drawLine(bean_math::vector2<T> pos1, bean_math::vector2<T> pos2) const {
        SDL_RenderLine(m_renderer, pos1.x, pos1.y, pos2.x, pos2.y);
    }

    template<typename T>
    void renderModule::drawPoint(bean_math::vector2<float> pos) const {
        SDL_RenderPoint(m_renderer, pos.x, pos.y);
    }

}
