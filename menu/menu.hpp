#pragma once

#include <raylib.h>
#include <string>

class Menu {
    public:
        Menu();

        void update();
        void draw();

        bool shouldStartGame() const;
        std::string getPlayerName() const;

    private:
        std::string playerName;
        bool startGame;

        Rectangle inputBox;
        Rectangle startButton;
};