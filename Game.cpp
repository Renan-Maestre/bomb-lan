#include "Game.hpp"

Game::Game()
    : player1(Vector2{100, 400}, RED) 
    // player2(Vector2{700, 400}, BLUE)
{}

void Game::update(){
    player1.update();
    // player2.update();
    bomb.update();

   if (bomb.isExploding())
    {
        if (bomb.hitPlayer(player1.getPosition(), player1.getRadius()))
        {
            // player 1 foi atingido
        }

        // if (bomb.hitPlayer(player2.getPosition(), player2.getRadius()))
        // {
        //     // player 2 foi atingido
        // }
    }

}

void Game::draw(){
  
    DrawGridBackGround();

    bomb.draw();
    player1.draw();
    // player2.draw();
    DrawText("Olha a Bomba", 300, 10, 30, RAYWHITE);
}

void Game::DrawGridBackGround(){
    Color background = Color{9, 14, 20, 255};
    Color grid = Color{20, 30, 40, 255};

    ClearBackground(background);

    int gridSize = 24;

    for (int x = 0; x < GetScreenWidth(); x += gridSize)
        DrawLine(x, 0, x, GetScreenHeight(), grid);

    for (int y = 0; y < GetScreenHeight(); y += gridSize)
        DrawLine(0, y, GetScreenWidth(), y, grid);
}