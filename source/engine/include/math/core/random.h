#pragma once
#include <random>

namespace bean_engine::bean_math::random {
    /**
     * @brief Generator for random numbers. MT19937.
     * @return Generator Object.
     */
    inline std::mt19937& generator() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }

    /**
     * @brief Assign the seed for the random number generator.
     * @param value Seed.
     */
    inline void seed(const uint32_t value) {
        generator().seed(value);
    }

    /**
     * @brief get a random int based on a min and max value.
     * @param min Lowest possible value for the generator.
     * @param max Highest possible value for the generator.
     * @return Generated value.
     */
    inline int32_t getInt(const int32_t min, const int32_t max) {
        std::uniform_int_distribution<> dist(min, max);
        return dist(generator());
    }

    /**
     * @brief get a random int based on a max value.
     * Get a random integer value based on a maximum value, where the minimum is assumed to be zero.
     * @param max Highest possible value for the generator.
     * @return Generated value.
     */
    inline int32_t getInt(const int32_t max) {
        return getInt(0, max - 1);
    }

    /**
     * @brief Engine Deprecated - Not recommended.
     * Get a random int based on the default values assigned by uniform int distribution.
     * @return Generated value.
     */
    inline int32_t getInt() {
        static std::uniform_int_distribution<> dist;
        return dist(generator());
    }

    /**
     * @brief Generate a random value on a type of your choice.
     * @tparam T Type of value to get.
     * @param min Lowest possible value.
     * @param max Highest possible value.
     * @return Generated value.
     */
    template <typename T = float>
    T getReal(T min, T max) {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(generator());
    }
    /**
     * @brief Generate a random value on a type of your choice.
     * Get a random value based on a maximum value, where the minimum is assumed to be zero.
     * @tparam T Type of value to get.
     * @param max Highest possible value.
     * @return Generated value.
     */
    template <typename T = float>
    T getReal(T max) {
        return getReal(static_cast<T>(0), static_cast<T>(max));
    }

    /**
     * @brief Engine Deprecated - Not recommended.
     * Get a random value based on the default values assigned by distribution.
     * @tparam T Type of value to get.
     * @return Generated value.
     */
    template <typename T = float>
    T getReal() {
        static std::uniform_real_distribution<T> dist(static_cast<T>(0), static_cast<T>(1));
        return dist(generator());
    }

    /**
     * @brief Get a random bool.
     * @return Randomized bool.
     */
    inline bool getBool() {
        static std::bernoulli_distribution dist(0.5);
        return dist(generator());
    }
}
