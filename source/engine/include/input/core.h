#pragma once
#include <array>
#include <vector>

#include "math/colors/color4.h"
#include "math/vectors/vector2.h"

namespace bean_engine::bean_input {

    enum InputMouseButtons {
        M_BUTTON_LEFT = 0,
        M_BUTTON_MIDDLE = 1,
        M_BUTTON_RIGHT = 2,
    };

    /**
     * A module whose purpose is to handle input operations.
     */
    class inputModule {
    public:
        inputModule();
        void tick();
        // KEYBOARD INPUT
        [[nodiscard]] bool getKeyDown(const uint8_t key) const {
            return m_KeyboardState[key];
        }
        [[nodiscard]] bool getPrevKeyDown(const uint8_t key) const {
            return m_prevKeyboardState[key];
        }

        [[nodiscard]] bool getKeyPressed(const uint8_t key) const {
            return !m_prevKeyboardState[key] && m_KeyboardState[key];
        }

        [[nodiscard]] bool getKeyReleased(const uint8_t key) const {
            return m_prevKeyboardState[key] && !m_KeyboardState[key];
        }

        // MOUSE INPUT
        [[nodiscard]] const bean_math::vector2<float>& getMousePosition() const {
            return m_MousePosition;
        };
        [[nodiscard]] const bean_math::vector2<float>& getLastMousePosition() const {
            return m_prevMousePosition;
        };
        [[nodiscard]] bool GetMouseButtonDown(const InputMouseButtons &buttons) const {
            return m_mouseButtonState[buttons];
        }
        [[nodiscard]] bool getPreviousMouseButtonDown(const InputMouseButtons &buttons) const {
            return m_prevMouseButtonState[buttons];
        }
    private:
        std::vector<bool> m_KeyboardState;
        std::vector<bool> m_prevKeyboardState;

        bean_math::vector2<float> m_MousePosition{0, 0};
        bean_math::vector2<float> m_prevMousePosition{0, 0};

        std::array<bool, 3> m_mouseButtonState{false, false, false};
        std::array<bool, 3> m_prevMouseButtonState{false, false, false};
    };
}
