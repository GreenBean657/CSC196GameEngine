#pragma once
#include <cmath>
#include <algorithm>
#include <random>
#include <cassert>
namespace bean_engine::bean_math {
    constexpr double PI = 3.14159265359;
    constexpr double twoPI = (2 * PI);
    constexpr double halfPI = (PI * 0.5);

    constexpr float degToRad(const float &degrees) {
        return degrees * (static_cast<float>(PI) / 180.0f);

    }
    constexpr float radToDeg(const float &radians) {
        return radians * (180.0f / static_cast<float>(PI));

    }

    using std::min;
    using std::max;
    using std::clamp;
    using std::sqrt;
    using std::sqrtf;
    using std::sin;
    using std::sinf;
    using std::cos;
    using std::cosf;
    using std::atan;
    using std::atan2;
    using std::atan2f;

}