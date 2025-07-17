#include "input/core.h"

#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_mouse.h>

namespace bean_engine::bean_input {
    inputModule::inputModule() {
        int32_t numKeys;
        const bool* curr_KeyboardState = SDL_GetKeyboardState(&numKeys);
        m_KeyboardState.resize(numKeys);
        m_prevKeyboardState.resize(numKeys);

std::copy_n(curr_KeyboardState, m_KeyboardState.size(), m_KeyboardState.begin());        m_prevKeyboardState = m_KeyboardState;
        return;
    }
}

void bean_engine::bean_input::inputModule::tick() {
    m_prevKeyboardState = m_KeyboardState;
    const bool* curr_keyboardState = SDL_GetKeyboardState(nullptr);
    std::copy_n(curr_keyboardState, m_KeyboardState.size(), m_KeyboardState.begin());
    m_prevMousePosition = m_MousePosition;
    const uint32_t mouseButtonState = SDL_GetMouseState(&m_MousePosition.x, &m_MousePosition.y);

    m_mouseButtonState[M_BUTTON_LEFT] = mouseButtonState & SDL_BUTTON_LMASK;
    m_mouseButtonState[M_BUTTON_MIDDLE] = mouseButtonState & SDL_BUTTON_MMASK;
    m_mouseButtonState[M_BUTTON_RIGHT] = mouseButtonState & SDL_BUTTON_RMASK;

}

