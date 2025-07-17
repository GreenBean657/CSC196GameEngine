#pragma once
#include <cassert>
#include <cmath>
#include <stdexcept>

namespace bean_engine::bean_math {
    template<typename T>
    struct vector3 {
        T x = 0;
        T y = 0;
        T z = 0;
        vector3() = default;
        vector3(T xx, T yy, T zz) {
            x = xx;
            y = yy;
            z = zz;
        }
        /**
        * @brief Returns the squared length of the vector.
        */
        [[nodiscard]] float lengthSqr() const {
            return ((x * x) + (y * y) + (z * z));
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
            if (index == 2) {
                return z;
            }
                throw std::out_of_range("Index out of range for vector3 Object");

        }

        vector3 operator + (const vector3& v) const {
            return vector3(x + v.x, y + v.y, z + v.z);
        }
        vector3 operator - (const vector3& v) const {
            return vector3(x - v.x, y - v.y, z - v.z);
        }
        vector3 operator * (const vector3& v) const {
            return vector3(x * v.x, y * v.y, z * v.z);
        }
        vector3 operator / (const vector3& v) const {
            assert(v.x != 0);
            assert(v.y != 0);
            assert(v.z != 0);
            return vector3(x / v.x, y / v.y, z / v.z);
        }

        vector3& operator += (const vector3& v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        vector3& operator -= (const vector3& v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }
        vector3& operator *= (const vector3& v) {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return *this;
        }
        vector3& operator /= (const vector3& v) {
            assert(v.x != 0);
            assert(v.y != 0);
            assert(v.z != 0);
            x /= v.x;
            y /= v.y;
            z /= v.z;
            return *this;
        }

        [[nodiscard]] vector3 operator + (const T& f) const {
            return vector3(x + f, y + f, z + f);
        }
        [[nodiscard]] vector3 operator - (const T& f) const {
            return vector3(x - f, y - f, z - f);
        }
        [[nodiscard]] vector3 operator * (const T& f) const {
            return vector3(x * f, y * f, z * f);
        }
        [[nodiscard]] vector3 operator / (const T& f) const {
            assert(f != 0);
            return vector3(x / f, y / f, z / f);
        }

        bool operator == (const vector3& v) const {
            return x == v.x && y == v.y && z == v.z;
        }

    };
}
