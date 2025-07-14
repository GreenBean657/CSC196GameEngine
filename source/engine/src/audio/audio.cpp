#include "audio/audio.h"

#include <iostream>
#include <bits/ostream.tcc>

namespace engine {
    bool AudioEngine::Init() {


        return true;
    }


    bool AudioEngine::AddSound(const std::string& filename, const std::string& name) {
        std::string key = (name.empty()) ? filename : name;

        //Check if key exists
        if (m_sounds.find(key) != m_sounds.end()) {
            std::cerr << "Sound already exists: " << key << std::endl;
            return false;
        }

        FMOD::Sound* sound = nullptr;
        FMOD_RESULT result = m_system->createSound(key.c_str(), FMOD_DEFAULT, 0, &sound);
        if (!CHECKFModResult(result)) return false;
        m_sounds[key] = sound;
        return true;
    }

    bool AudioEngine::PlaySound(const std::string& name) {

        if (m_sounds.find(name) == m_sounds.end()) {
            std::cerr << "Sound not found: " << name << std::endl;
        }

        FMOD_RESULT result = m_system->playSound(m_sounds[name] 0, false, false);
        if (!CHECKFModResult(result)) return false;
        return true;
    }
}
