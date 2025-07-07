#pragma once

#include <string>
#include <SDL3/SDL_render.h>

namespace engine {
    class Renderer {

        public:
            Renderer() = default;

            [[nodiscard]] bool Initialize();
            [[nodiscard]] bool CreateWindow(
                const std::string& name = "RenderedWindow",
                const uint32_t& width = 1920,
                const uint32_t& height = 1080
                );

            void setColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a = 255);

            void DrawLine(const uint32_t& x1, const uint32_t& y1, const uint32_t& x2, const uint32_t& y2);
            void DrawPoint(const uint32_t& x, const uint32_t& y) const;

            void Present();
            void Clear();

            void Kill();

            ~Renderer() = default;
        private:
            SDL_Window* window = nullptr;
            SDL_Renderer* renderer = nullptr;
    };
}
