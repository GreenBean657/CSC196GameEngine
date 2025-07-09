#include "../../include/input/inputsystem.h"
#include <SDL3/SDL.h>

#include "engine.h"

using namespace engine;

bool InputSystem::Initialize() {
    int32_t numKeys;
    const bool* curr_keyboardState = SDL_GetKeyboardState(&numKeys);
    m_keyboardState.resize(numKeys);
    m_prevKeyboardState.resize(numKeys);
    std::copy(curr_keyboardState, curr_keyboardState + numKeys, m_keyboardState.begin());
    m_prevKeyboardState = m_keyboardState;
    return true;
}

void InputSystem::Tick() {
    m_prevKeyboardState = m_keyboardState;
    const bool* curr_keyboardState = SDL_GetKeyboardState(nullptr);
    std::copy(curr_keyboardState, curr_keyboardState + m_keyboardState.size(), m_keyboardState.begin());

    m_lastMousePosition = m_mousePosition;
    uint32_t mouseButtonState = SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);

    m_mouseButtonState[0] = (mouseButtonState & SDL_BUTTON_LMASK);
    m_mouseButtonState[1] = (mouseButtonState & SDL_BUTTON_MMASK);
    m_mouseButtonState[2] = (mouseButtonState & SDL_BUTTON_RMASK);
}
