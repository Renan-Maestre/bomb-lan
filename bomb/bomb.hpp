#pragma once

#include <raylib.h>

class Bomb {
    public:
        Bomb();

        void update();
        void draw();

        bool isExploding() const;


    bool hitPlayer(
        Vector2 playerPosition,
        float playerRadius
    ) const;

    private: 
        Vector2 position;
        float timer;
        float explosionTimer;
        float explosionRadius;
        bool exploding;
        void respawn();
    };