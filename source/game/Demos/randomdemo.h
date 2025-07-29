#pragma once

#include <iomanip>
#include <iostream>
#include "math/core/random.h"
using namespace bean_engine::bean_math::random;
inline int demo() {
    // Test getInt() variants
    std::cout << "Integer Functions:\n";
    std::cout << "getInt(): " << getInt() << "\n";
    std::cout << "getInt(): " << ::getInt() << "\n";
    std::cout << "getInt(10): " << ::getInt(10) << "\n";
    std::cout << "getInt(10): " << ::getInt(10) << "\n";
    std::cout << "getInt(5, 15): " << ::getInt(5, 15) << "\n";
    std::cout << "getInt(5, 15): " << ::getInt(5, 15) << "\n";
    std::cout << "getInt(-10, 10): " << ::getInt(-10, 10) << "\n\n";

    // Test getReal() variants with float
    std::cout << "Float Functions:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "getReal<float>(): " << ::getReal<float>() << "\n";
    std::cout << "getReal<float>(): " << ::getReal<float>() << "\n";
    std::cout << "getReal<float>(5.0f): " << ::getReal<float>(5.0f) << "\n";
    std::cout << "getReal<float>(2.5f, 7.5f): " << ::getReal<float>(2.5f, 7.5f) << "\n";
    std::cout << "getReal<float>(-1.0f, 1.0f): " << ::getReal<float>(-1.0f, 1.0f) << "\n\n";

    // Test getReal() variants with double
    std::cout << "Double Functions:\n";
    std::cout << std::setprecision(10);
    std::cout << "getReal<double>(): " << ::getReal<double>() << "\n";
    std::cout << "getReal<double>(100.0): " << ::getReal<double>(100.0) << "\n";
    std::cout << "getReal<double>(0.0, 2.0): " << ::getReal<double>(0.0, 2.0) << "\n\n";

    // Test getBool()
    std::cout << "Boolean Functions:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "getBool(): " << std::boolalpha << ::getBool() << "\n";
    }
    std::cout << "\n";
    return 0;
}