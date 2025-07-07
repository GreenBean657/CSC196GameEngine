template<typename T>
struct Vector2 {
    T x, y;
    Vector2() = default;
    Vector2(T xx, T yy) {
        x = xx;
        y = yy;
    }
};

using IVec2 = Vector2<int>;
using FVec2 = Vector2<float>;