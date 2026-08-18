#include "player.hpp"

Player::Player(Vector2 startPosition , Color color){
    position = startPosition;
    speed = 200.0f;
    this->color = color;
}

void Player::update(){
    float frame = GetFrameTime();

    if(IsKeyDown(KEY_W)){
        position.y -= speed * frame;
    }else if (IsKeyDown(KEY_S)){
        position.y += speed * frame;
    } else if (IsKeyDown(KEY_A)){
        position.x -= speed * frame;
    } else if (IsKeyDown(KEY_D)){
        position.x += speed * frame;
    }

    if(position.y - 70  < 0){
        position.y = 70;
    } else if (position.y + 20 > GetScreenHeight()){
        position.y = GetScreenHeight() - 20;
    }

    if(position.x -20 < 0){
        position.x = 20;
    } else if (position.x + 20 > GetScreenWidth()){
        position.x = GetScreenWidth() - 20;
    }

}

void Player::draw(){
    DrawCircleV(position, 20, color);
}

Vector2 Player::getPosition() const{
    return position;
}

float Player::getRadius() const{
    return 20.0f;
}