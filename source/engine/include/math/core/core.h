#pragma once
#include <cmath>
#include <algorithm>
#include <random>
#include <cassert>
namespace bean_engine::bean_math {
    constexpr double PI = 3.14159265359;
    constexpr double twoPI = (2 * PI);
    constexpr double halfPI = (PI * 0.5);

    constexpr double degToRad(const double &degrees) {
        return degrees * (PI / 180.0);

    }
    constexpr double radToDeg(const double &radians) {
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

    inline int getRandomInt(const int min = 0, const int max = 100) {
        assert(max >= min);
        std::mt19937 rand(std::random_device{}());
        std::uniform_int_distribution dist(min, max);
        return dist(rand);
    }

    inline double getRandomDouble(const double min = 0.0, const double max = 1.0) {
        assert(max >= min);
        std::mt19937 rand(std::random_device{}());
        std::uniform_real_distribution dist(min, max);
        return dist(rand);
    }
}