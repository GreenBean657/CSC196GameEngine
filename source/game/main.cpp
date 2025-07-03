#include <iostream>
#include "engine.h"

#include <iostream>


int main() {
    std::cout << engine::math::clamp(3, 1, 3);
    std::cout << "Hello World (From Game)!" << std::endl;
    engine::Hello();
    std::cout << engine::math::PI;
    std::cout << std::endl;
    std::cout << engine::math::getRandomDouble();
    return 0;
}
