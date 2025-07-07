#include <cstdint>

template<typename T>
struct Vector2 {
    T x, y;
    Vector2() = default;
    Vector2(T xx, T yy) {
        x = xx;
        y = yy;
    }
};

using UIVec2 = Vector2<uint32_t>;
using IVec2 = Vector2<int32_t>;
using FVec2 = Vector2<float>;
