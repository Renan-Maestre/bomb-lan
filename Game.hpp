#pragma once
#define GAME_HPP

#include <raylib.h>
#include "player/player.hpp"
#include "bomb/bomb.hpp"
#include "menu/menu.hpp"
#include "safeArea/safeArea.hpp"
#include <string>

enum class GameState {
    MENU,PLAYING
};
class Game {
    public:
        Game();

        void update();
        void draw();
        
    private:
        Player player1;
        Bomb bomb;
        // Player player2;
        Menu menu;
        GameState state;
        SafeArea safeArea;
        std::string playerName;

        void DrawGridBackGround();
    };
