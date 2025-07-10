#pragma once
#include <vector>
#include <SDL3/SDL_scancode.h>
#include "math/vector.h"
#include <array>

namespace engine {
    enum InputMouseButtons {
        M_BUTTON_LEFT = 0,
        M_BUTTON_MIDDLE = 1,
        M_BUTTON_RIGHT = 2,
    };
    class InputSystem {
        public:
            InputSystem() = default;

            [[nodiscard]] bool Initialize();

            void Tick();

            [[nodiscard]] bool getKeyDown(const uint8_t key) const {
                return m_keyboardState[key];
            }
            [[nodiscard]] bool getPrevKeyDown(const uint8_t key) const {
                return m_prevKeyboardState[key];
            }

            [[nodiscard]] bool getKeyPressed(const uint8_t key) const {
                return !m_prevKeyboardState[key] && m_keyboardState[key];
            }

            [[nodiscard]] bool getKeyReleased(const uint8_t key) const {
                return m_prevKeyboardState[key] && !m_keyboardState[key];
            }

            [[nodiscard]] const math::Vector2<float>& getMousePosition() const {
                return m_mousePosition;
            };

            [[nodiscard]] const math::Vector2<float>& getLastMousePosition() const {
                return m_lastMousePosition;
            };

            [[nodiscard]] bool GetMouseButtonDown(const InputMouseButtons &buttons) const {
                return m_mouseButtonState[buttons];
            }

            //Shutdown not required.
            ~InputSystem() = default;
        private:
            std::vector<bool> m_keyboardState;
            std::vector<bool> m_prevKeyboardState;

            engine::math::Vector2<float> m_mousePosition{0, 0};
            engine::math::Vector2<float> m_lastMousePosition{0, 0};

            std::array<bool, 3> m_mouseButtonState{false, false, false};
            std::array<bool, 3> m_prevMouseButtonState{false, false, false};
    };
}
