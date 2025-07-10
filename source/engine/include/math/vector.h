#pragma once
#include <cassert>
#include <cmath>
#include <stdexcept>


namespace engine::math {
    template<typename T>
    struct Vector2 {
        T x, y;
        Vector2() = default;
        Vector2(T xx, T yy) {
            x = xx;
            y = yy;
        }

        /**
         * @brief Returns the squared length of the vector.
         */
        [[nodiscard]] float LengthSqr() const {
            return ((x * x) + (y * y));
        }

        /**
         * @brief Returns the length of the vector.
         */
        [[nodiscard]] float Length() const {
            return sqrtf(LengthSqr());
        }


        T operator [] (const uint32_t index) const {
            if (index == 0) {
                return &x;
            }
            if (index == 1) {
                return &y;
            }
            assert(index < 2);
            throw std::out_of_range("index out of range for vector2 Object");
        }

        T& operator [] (const uint32_t index) {
            if (index == 0) {
                return &x;
            }
            if (index == 1) {
                return &y;
            }
            assert(index < 2);
            throw std::out_of_range("index out of range for vector2 Object");
        }


        Vector2 operator + (const Vector2& v) const {
            return Vector2(x + v.x, y + v.y);
        }
        Vector2 operator - (const Vector2& v) const {
            return Vector2(x - v.x, y - v.y);
        }
        Vector2 operator * (const Vector2& v) const {
            return Vector2(x * v.x, y * v.y);
        }
        Vector2 operator / (const Vector2& v) const {
            return Vector2(x / v.x, y / v.y);
        }


        Vector2& operator += (const Vector2& v) const {
            x += v.x;
            y += v.y;
            return *this;
        }
        Vector2& operator -= (const Vector2& v) const {
            x -= v.x;
            y -= v.y;
            return *this;
        }
        Vector2& operator *= (const Vector2& v) const {
            x *= v.x;
            y *= v.y;
            return *this;
        }
        Vector2& operator /= (const Vector2& v) const {
            x /= v.x;
            y /= v.y;
            return *this;
        }


        Vector2 operator + (const float& f) const {
            return Vector2(x + f, y + f);
        }
        Vector2 operator - (const float& f) const {
            return Vector2(x - f, y - f);
        }
        Vector2 operator * (const float& f) const {
            return Vector2(x * f, y * f);
        }
        Vector2 operator / (const float& f) const {
            return Vector2(x / f, y / f);
        }

        Vector2& operator += (const float& f) {
            return *this = *this + f;
        }
        Vector2& operator -= (const float& f) {
            return *this = *this - f;
        }
        Vector2& operator *= (const float& f) {
            return *this = *this * f;
        }
        Vector2& operator /= (const float& f) {
            return *this = *this / f;
        }
    };

    using UIVec2 = Vector2<uint32_t>;
    using IVec2 = Vector2<int32_t>;
    using FVec2 = Vector2<float>;
}
