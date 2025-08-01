#pragma once
#include <string>

struct TTF_Font;

namespace bean_engine::bean_text {
    class Font {
    public:
        Font() = default;
        ~Font();

        bool load(const std::string& filename, const int& size);

    private:
        friend class Text;
        TTF_Font* m_tffFont = nullptr;
    };
}