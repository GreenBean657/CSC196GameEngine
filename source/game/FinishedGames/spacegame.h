#pragma once
#include "env/game.h"

class spaceGame final : bean_engine::game {

    public:
    void init() override;
    void update() override;
    void kill() override;
    void draw() override;

private:

};

#include "spacegame.hpp"