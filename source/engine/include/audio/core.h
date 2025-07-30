#pragma once
#include <map>
#include <string>
#include <../../thirdparty/fmod/core/inc/fmod.hpp>
#include <../../thirdparty/fmod/core/inc/fmod_errors.h>
namespace bean_engine::bean_audio {
    class audioModule {
        public:
            audioModule();

            void tick() const;

            [[nodiscard]] bool addSound(const std::string& filepath, const std::string& name);

            bool playSound(const std::string& filepath);

            void kill() const;

        ~audioModule() {
            kill();
        }
        private:
            static bool moduleEcc(const bool &hardLockdown, const FMOD_RESULT &result);
        FMOD::System* m_system = nullptr;
        std::pmr::map<std::string, FMOD::Sound*> m_sounds;
    };
}