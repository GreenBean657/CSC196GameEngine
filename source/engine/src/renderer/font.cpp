#include "renderer/font.h"

#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>
struct TFF_Font;

namespace bean_engine {
    bean_text::Font::~Font() {
        if (m_tffFont != nullptr) {
            TTF_CloseFont(m_tffFont);
        }
    }

    bool bean_text::Font::load(const std::string& filename, const int& size) {
        TTF_Init();
        m_tffFont = TTF_OpenFont(filename.c_str(), size);
        if (m_tffFont == nullptr) {
            std::cerr << "Failed to load font file: " << filename << std::endl;
            return false;
        }
        return true;
    }

}
