#pragma once
#include <algorithm>
#include <random>

namespace engine::math {
    constexpr double PI = 3.14159265359;
    constexpr double twoPI = (2 * PI);
    constexpr double halfPI = (PI * 0.5);

    constexpr double degToRad(double degrees) {
        return degrees * (PI / 180.0);

    }
    constexpr double radToDeg(double radians) {
        return radians * (180.0 / PI);

    }
    using std::min;
    using std::max;
    using std::clamp;
    using std::sqrt;
    using std::sqrtf;
    using std::sin;
    using std::sinf;
    using std::cos;

    inline int getRandomInt(int max) {
        return rand() % max;
    }
    inline int getRandomInt(int min, int max) {
        return min + getRandomInt(max - min + 1);
    }

        /// Get a random double between 0 and 1.
        /// @return Acquired double.
        ///
    inline double getRandomDouble() {
        std::mt19937 rand(std::random_device{}());
        std::uniform_real_distribution dist(0.0, 1.0);
        return dist(rand);
    }


} // namespace engine::math

