#pragma once
#define GAME_HPP

#include <raylib.h>
#include "player/player.hpp"
#include "bomb/bomb.hpp"

class Game {
    public:
        Game();

        void update();
        void draw();
        
    private:
        Player player1;
        Bomb bomb;
        // Player player2;

        void DrawGridBackGround();
    };
