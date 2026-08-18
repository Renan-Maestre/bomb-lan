#include "bomb.hpp"

Bomb::Bomb()
{
    explosionRadius = 100.0f;
    respawn();
}

void Bomb::respawn()
{
    position.x = GetRandomValue(50, GetScreenWidth() - 50);
    position.y = GetRandomValue(50, GetScreenHeight() - 50);

    timer = 5.0f;
    explosionTimer = 1.0f;
    exploding = false;
}

void Bomb::update()
{
    float dt = GetFrameTime();

    if (!exploding)
    {
        timer -= dt;

        if (timer <= 0.0f)
        {
            exploding = true;
            explosionTimer = 0.5f;
        }
    }
    else
    {
        explosionTimer -= dt;

        if (explosionTimer <= 0.0f)
        {
            respawn();
        }
    }
}

void Bomb::draw()
{
    if (!exploding)
    {
        DrawCircleV(position, 15, YELLOW);
    }
    else
    {
            DrawCircleV(
                position,
                explosionRadius,
                Color{255, 100, 0, 100}
            );

        DrawCircleLines(
            (int)position.x,
            (int)position.y,
            explosionRadius,
            ORANGE
        );
    }
}

bool Bomb::isExploding() const
{
    return exploding;
}

bool Bomb::hitPlayer(Vector2 playerPosition, float playerRadius) const
{
    return CheckCollisionCircles(
        position,
        explosionRadius,
        playerPosition,
        playerRadius
    );
}