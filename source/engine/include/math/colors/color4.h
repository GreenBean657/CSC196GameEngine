#pragma once
#include <cstdint>
#include "math/core/core.h"

namespace bean_engine::bean_math {

    // Color4 Structures
    struct color4 {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        color4(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
        color4(const uint8_t r, const uint8_t g, const uint8_t b) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = 255;
        }


    };

    struct f_color4 {
        float r;
        float g;
        float b;
        float a;

        f_color4(const float r, const float g, const float b, const float a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
        f_color4(const float r, const float g, const float b) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = 1.0f;
        }
    };

    //Color 4 functions

    /**
     * @brief Get a random color4 object.\n
     * Generate a randomized color4 object, with randomized alpha and base coloring.
     * @param randomize_alpha Should alpha be randomized? If not, defaults to no transparency.
     * @return Random Color4.
     */
    [[nodiscard]] inline color4 random_color4(const bool randomize_alpha = false) {
        const auto r = static_cast<uint8_t>(getRandomInt(0, 255));
        const auto g = static_cast<uint8_t>(getRandomInt(0, 255));
        const auto b = static_cast<uint8_t>(getRandomInt(0, 255));
        auto a = static_cast<uint8_t>(getRandomInt(0, 255));
        if (!randomize_alpha) {
            a = 255;
        }
        return {r, g, b, a};
    }
    /**
     * @brief Get a random float color4 object.\n
     * Generate a randomized floating point color4 object, with randomized alpha and base coloring.
     * @param randomize_alpha Should alpha be randomized? If not, defaults to no transparency.
     * @return Random floating Point Color4.
     */
    [[nodiscard]] inline f_color4 f_random_color4(const bool randomize_alpha = false) {
        const auto r = static_cast<float>(getRandomDouble(0, 1.0));
        const auto g = static_cast<float>(getRandomDouble(0, 1.0));
        const auto b = static_cast<float>(getRandomDouble(0, 1.0));
        auto a = static_cast<float>(getRandomDouble(0, 1.0));
        if (!randomize_alpha) {
            a = 1.0f;
        }
        return {r, g, b, a};
    }

}
