#include "engine.h"

#include <iostream>
#include <fmt/core.h>
#include <SDL3/SDL.h>
#include "input/inputsystem.h"
#include "render/cpurender.h"
namespace engine {
    void HelloWorld() {
        fmt::print("Hello from engine!\n");
    }
}
