#pragma once
#include <chrono>
namespace Engine {
    class Time {

        public:
            Time() {
                startTime = clock::now();
                frameTime = clock::now();
            }

            void Tick() {
                const clock::time_point now = clock::now();
                m_time = std::chrono::duration<float>(now - startTime).count();
                d_time = std::chrono::duration<float>(now - frameTime).count();
                frameTime = now;
            }
            void Reset() {
                startTime = clock::now();
            }

            float getTime() const {
                return m_time;
            }

            float getDeltaTime() const {
                return d_time;
            }

        private:
            using clock = std::chrono::high_resolution_clock;

            float m_time = 0.0f;
            float d_time = 0.0f;
            clock::time_point startTime;
            clock::time_point frameTime;
    };
}