#include <iostream>
#include "engine.h"
#include <iostream>
#include "render/cpurender.h"
using namespace engine;
int main() {
    return engine::cpurender::drawRandomWindow("My Game", 1024);

}
