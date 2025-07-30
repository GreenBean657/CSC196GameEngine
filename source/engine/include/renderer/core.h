#pragma once
#include <string>
#include <SDL3/SDL.h>

#include "math/colors/color4.h"
#include "math/vectors/vector2.h"

namespace bean_engine::bean_renderer {
    /**
     * A module whose purpose is to handle rendering operations.
     */
    class renderModule {
    public:
        /**
         * Create a new window.
         * @param name Name at appears at the top of the window.
         * @param width Width of the window in pixels.
         * @param height Height of the window in pixels.
         * @throws RunTimeError SDL fails to initialize, permissions fault or non-GUI environment.
         * @throws InvalidArgument SDL recieved a negative window size.
         */
        explicit renderModule(const std::string& name = "My Application", const uint32_t& width = 600, const uint32_t& height = 600);

        /**
         * Set the draw color for the window cursor.
         * @param color Color4 Object, as (255, 255, 255, 255).
         */
        void setDrawColor(bean_math::color4 color) const;

        /**
        * Set the draw color for the window cursor.
        * @param color Color4 Object, as (1, 1, 1, 1)
        */
        void setDrawColor(const bean_math::f_color4& color) const;

        /**
         * @brief Draws a line.
         * Draw a new line. Requires the color to be set prior to the operation.
         * @param pos1 (X, Y) of point 1.
         * @param pos2 (X, Y) of point 2.
         */
        template<typename T>
        void drawLine(bean_math::vector2<T> pos1, bean_math::vector2<T> pos2) const;

        /**
         * @brief Draws a point.
         * @param pos (X, Y) of point.
         */
        template<typename T>
        void drawPoint(bean_math::vector2<float> pos) const;

        /**
         * Clear the renderer.
         */
        void clear() const;

        /**
         * Present the renderer to the user.
         */
        void present() const;

        /**
        * @brief True = Exit loop, false = remain in loop.
        *
        * Check if a renderer has been closed. Used in the render
        * process loop.
        * @return TRUE / FALSE, SDL_EVENT_QUIT flag received.
        */
        bool tryExit();

        /**
         * @brief Destroys the window.
         */
        ~renderModule();
        SDL_Renderer* m_renderer = nullptr;

        void kill() const;
    protected:

    private:
        SDL_Window* m_window = nullptr;
    };
}

#include "./core.hpp"