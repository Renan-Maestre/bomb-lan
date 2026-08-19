#include <raylib.h>
#include "Game.hpp"

int main(){
    InitWindow(800,800, "Olha a Bomba");
    SetTargetFPS(60);

    Game game;
    while(!WindowShouldClose()){    

        game.update();

        BeginDrawing();
        // ClearBackground(RAYWHITE);
        
        game.draw();
        
        EndDrawing();

    }

    CloseWindow();
    return 0;
}