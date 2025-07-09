#pragma once
#include <vector>
#include <SDL3/SDL_scancode.h>
#include "math/vector.h"
#include <array>

namespace engine {
    class InputSystem {
        public:
            InputSystem() = default;

            bool Initialize();
            void Tick();

            [[nodiscard]] bool getKeyDown(uint8_t key) const {
                return m_keyboardState[key];
            }
            [[nodiscard]] bool getPrevKeyDown(uint8_t key) const {
                return m_prevKeyboardState[key];
            }

            [[nodiscard]] bool getKeyPressed(uint8_t key) const {
                return !m_prevKeyboardState[key] && m_keyboardState[key];
            }

            [[nodiscard]] bool getKeyReleased(uint8_t key) const {
                return m_prevKeyboardState[key] && !m_keyboardState[key];
            }

            [[nodiscard]] const Vector2<float>& getMousePosition() const {
                return m_mousePosition;
            };

            [[nodiscard]] const Vector2<float>& getLastMousePosition() const {
                return m_lastMousePosition;
            };

            //Shutdown not required.
            ~InputSystem() = default;
        private:
            std::vector<bool> m_keyboardState;
            std::vector<bool> m_prevKeyboardState;

            Vector2<float> m_mousePosition{0, 0};
            Vector2<float> m_lastMousePosition{0, 0};

            std::array<bool, 3> m_mouseButtonState{false, false, false};
            std::array<bool, 3> m_prevMouseButtonState{false, false, false};
    };
}
