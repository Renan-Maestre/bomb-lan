#include "safeArea.hpp"

SafeArea::SafeArea(){
    safeArea.x = 0;
    safeArea.y = 0;
    safeArea.width = GetScreenWidth() - 10;
    safeArea.height = GetScreenHeight() -10;
}

void SafeArea::update(){

    float speed = 0.5f;

   
    if (safeArea.width > 100 && safeArea.height > 100)
    {
        safeArea.x += speed;
        safeArea.y += speed;

        safeArea.width -= speed * 2;
        safeArea.height -= speed * 2;
    }
}
void SafeArea::draw(){


    Color background = Color{158, 158, 158, 150};

    // Cima
    DrawRectangle(
        0,
        0,
        GetScreenWidth(),
        safeArea.y,
        background
    );

    // Baixo
    DrawRectangle(
        0,
        safeArea.y + safeArea.height,
        GetScreenWidth(),
        GetScreenHeight() - (safeArea.y + safeArea.height),
        background
    );

    // Esquerda
    DrawRectangle(
        0,
        safeArea.y,
        safeArea.x,
        safeArea.height,
        background
    );

    // Direita
    DrawRectangle(
        safeArea.x + safeArea.width,
        safeArea.y,
        GetScreenWidth() - (safeArea.x + safeArea.width),
        safeArea.height,
        background
    );
}