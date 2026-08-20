#pragma once

#include <raylib.h>
#include "../safeArea/safeArea.hpp"

class Bomb {
    public:
        Bomb(const SafeArea& safeArea);

        void update(const SafeArea& safeArea);
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
        void respawn(const SafeArea& safeArea);
    };