#include "render/renderer.h"

#include <iostream>
#include <bits/ostream.tcc>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
namespace engine {
        bool Renderer::Initialize() {
                if (!SDL_Init(SDL_INIT_VIDEO)) {
                        std::cerr << "SDL_Init Error:"<< SDL_GetError() << std::endl;
                        return false;
                }
                return true;
        }

        bool Renderer::CreateWindow(const std::string &name, const uint32_t &width, const uint32_t &height) {
                //.c_str() = Convert string to C style string (just data, no advanced concatenation and such)
                window = SDL_CreateWindow(name.c_str(), width, height, 0);
                if (window == nullptr) {
                        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
                        SDL_Quit();
                        return false;
                }

                renderer = SDL_CreateRenderer(window, nullptr);
                if (renderer == nullptr) {
                        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        return false;
                }

                return true;
        }

        void Renderer::setColor(const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a) {
                SDL_SetRenderDrawColor(renderer, r, g, b, a);
        }

        void Renderer::DrawLine(const float &x1, const float &y1, const float &x2, const float &y2) {
                SDL_RenderLine(renderer, x1, y1, x2, y2);
        }

        void Renderer::DrawPoint(const float& x, const float& y) const {
                SDL_RenderPoint(renderer, x, y);
        }

        void Renderer::Clear() {
                SDL_RenderClear(renderer);
        }

        void Renderer::Present() {
                SDL_RenderPresent(renderer);
        }

        void Renderer::Kill() {
                SDL_DestroyWindow(window);
                SDL_Quit();
        }
}



