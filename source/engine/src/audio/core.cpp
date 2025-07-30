#include "audio/core.h"

#include <iostream>
#include <bits/ostream.tcc>

namespace bean_engine::bean_audio {
    bool audioModule::moduleEcc(const bool &hardLockdown, const FMOD_RESULT &result) {
        if (result != FMOD_OK) {
            std::cerr << "Error: " << FMOD_ErrorString(result) << std::endl;
            if (hardLockdown) {
                throw std::runtime_error("Error operating audio module.");
            }
            return false;
        }
        return true;
    }


    audioModule::audioModule() {
        moduleEcc(true, FMOD::System_Create(&m_system));
        moduleEcc(true, (m_system->init(32, FMOD_INIT_NORMAL, nullptr)));
    }

    void audioModule::tick() const {
        moduleEcc(false, m_system->update());
    }

    void audioModule::kill() const {
        moduleEcc(false, m_system->release());
    }



    bool audioModule::addSound(const std::string &filepath, const std::string &name) {
        FMOD::Sound* sound = nullptr;
        std::string key;
        if (name.empty()) {
            key = filepath;
        } else {
            key = name;
        }

        if (m_sounds.contains(key)) {
            std::cerr << "Sound " << key << " already exists." << std::endl;
            return false;
        }

        const FMOD_RESULT result = m_system->createSound(filepath.c_str(), FMOD_DEFAULT, nullptr, &sound);
        if (!moduleEcc(false, result)) return false;
        m_sounds[key] = sound;
        return true;
    }

    bool audioModule::playSound(const std::string &key) {
        if (m_sounds.contains(key) == false) {
            std::cerr << "Sound " << key << " does not exist." << std::endl;
            return false;
        }

        return moduleEcc(false, m_system->playSound(m_sounds[key], nullptr, false, nullptr));
    }

}
