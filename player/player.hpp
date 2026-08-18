#pragma once

#include <raylib.h>

class Player {
    public:
        Player(Vector2 startPosition , Color color);

        void update();
        void draw();
        Vector2 getPosition() const;
        float getRadius() const;

    private: 
        Vector2 position;
        float speed;
        Color color;
};