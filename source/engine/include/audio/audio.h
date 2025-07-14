#pragma once
#include <string>

namespace engine {
    class AudioEngine {
        public:
        AudioEngine() = default;
        bool Init();
        void Shutdown();

        void Update();

        bool AddSound(const std::string& filename, const std::string& name = "");
        bool PlaySound(const std::string& name);

        bool RemoveSound(const std::string& filename);
    };
}