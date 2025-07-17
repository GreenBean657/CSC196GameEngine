#pragma once
#include <cassert>
#include <cmath>
#include <stdexcept>

namespace bean_engine::bean_math {
    template<typename T>
    struct vector2 {
        T x = 0;
        T y = 0;
        vector2() = default;

        vector2(T xx, T yy) {
            x = xx;
            y = yy;
        }
        /**
        * @brief Returns the squared length of the vector.
        */
        [[nodiscard]] float lengthSqr() const {
            return ((x * x) + (y * y));
        }
        [[nodiscard]] float length() const {
            return sqrtf(lengthSqr());
        }

        T operator[](const size_t index) const {
            if (index == 0) {
                return x;
            }
            if (index == 1) {
                return y;
            }
                throw std::out_of_range("Index out of range for vector2 Object");
        }

        [[nodiscard]] vector2 operator + (const vector2& v) const {
            return vector2(x + v.x, y + v.y);
        }
        [[nodiscard]] vector2 operator - (const vector2& v) const {
            return vector2(x - v.x, y - v.y);
        }
        [[nodiscard]] vector2 operator * (const vector2& v) const {
            return vector2(x * v.x, y * v.y);
        }
        [[nodiscard]] vector2 operator / (const vector2& v) const {
            assert(v.x != 0);
            assert(v.y != 0);
            return vector2(x / v.x, y / v.y);
        }

        vector2& operator += (const vector2& v) {
            x += v.x;
            y += v.y;
            return *this;
        }
        vector2& operator -= (const vector2& v) {
            x -= v.x;
            y -= v.y;
            return *this;
        }
        vector2& operator *= (const vector2& v) {
            x *= v.x;
            y *= v.y;
            return *this;
        }
        vector2& operator /= (const vector2& v) {
            assert(v.x != 0);
            assert(v.y != 0);
            x /= v.x;
            y /= v.y;
            return *this;
        }

        [[nodiscard]] vector2 operator + (const T& f) const {
            return vector2(x + f, y + f);
        }
        [[nodiscard]] vector2 operator - (const T& f) const {
            return vector2(x - f, y - f);
        }
        [[nodiscard]] vector2 operator * (const T& f) const {
            return vector2(x * f, y * f);
        }
        [[nodiscard]] vector2 operator / (const T& f) const {
            assert(f != 0);
            return vector2(x / f, y / f);
        }

        bool operator == (const vector2& v) const {
            return x == v.x && y == v.y;
        }

    };
}
