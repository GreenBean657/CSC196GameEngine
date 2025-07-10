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

            static bool tryExit() {
                SDL_Event polled;
                while (SDL_PollEvent(&polled)) {
                    if (polled.type == SDL_EVENT_QUIT) {
                        return true;
                    }
                }
            return false;
            }

            void setColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a = 255);

            void DrawLine(const float &x1, const float &y1, const float &x2, const float &y2);
            void DrawPoint(const float &x, const float &y) const;

            void Present();
            void Clear();

            void Kill();

            ~Renderer() = default;
        private:
            SDL_Window* window = nullptr;
            SDL_Renderer* renderer = nullptr;
    };
}
