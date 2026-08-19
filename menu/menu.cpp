#include "menu.hpp"

Menu::Menu(){
    playerName = "";
    startGame = false;

    inputBox = { 250, 250, 300, 50 };
    startButton = { 300, 330, 200, 60 };
}

void Menu::update(){

    //pegar os inputs 
    int key = GetCharPressed();

    while (key > 0)
    {
        if(key >= 32 && key <= 125 && playerName.size() < 20) // Limite de tamanho do nome
        {
            playerName += (char)key;
        }
        key = GetCharPressed();
    }

    //backspace
    if(IsKeyPressed(KEY_BACKSPACE) && !playerName.empty())
    {
        playerName.pop_back();
    }

    Vector2 mouse = GetMousePosition();

    bool mouseOverButton = CheckCollisionPointRec(mouse, startButton);

    if(mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !playerName.empty())
    {
        startGame = true;
    }

    if(((mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) ||  IsKeyPressed(KEY_ENTER) ) && !playerName.empty()){
          startGame = true;
     }
}

void Menu::draw(){
    ClearBackground(Color{18, 20, 43, 255});

    //titulo
    const char* title = "BOMB ARENA";

    int titleSize = 60;
    int titleWidth = MeasureText(title, titleSize);

    //label
    DrawText(title, GetScreenWidth( ) / 2 - titleWidth / 2, 100, titleSize, RED);
    
    //campo
    DrawRectangleRec(inputBox, WHITE);
    DrawRectangleLinesEx(inputBox, 3, BLACK);


    if(playerName.empty()){
        DrawText("Digite seu nome", (int)inputBox.x + 10, (int)inputBox.y + 15, 20, BLACK);
    }else{
         DrawText(playerName.c_str(), (int)inputBox.x + 10, (int)inputBox.y + 15, 20, BLACK);
    }


    //Botão

    Vector2 mouse = GetMousePosition();

    bool hover = CheckCollisionPointRec(mouse, startButton);

    Color buttonColor = hover ? SKYBLUE : BLUE;

    DrawRectangleRec(startButton, buttonColor);
    DrawRectangleLinesEx(startButton, 2, WHITE);


    const char* buttonText = "Iniciar";
    int textSize = 25;
    int textWidth = MeasureText(buttonText, textSize);

    DrawText(buttonText, (int)startButton.x + startButton.width / 2 - textWidth / 2, (int)startButton.y + startButton.height / 2 - textSize / 2, textSize, WHITE);


}

bool Menu::shouldStartGame() const {
    return startGame;
}

std::string Menu::getPlayerName() const {
    return playerName;
}