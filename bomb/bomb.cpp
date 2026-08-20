#include "bomb.hpp"

Bomb::Bomb(const SafeArea& safeArea)
{
    explosionRadius = 100.0f;

    position = { 0, 0 };

    timer = 0.0f;
    explosionTimer = 0.0f;
    exploding = false;
    respawn(safeArea);
}

void Bomb::respawn(const SafeArea& safeArea)
{
    Vector4 area = safeArea.getAreaLivre();

    position.x = GetRandomValue(area.x + 25, area.x + area.z - 25);
    position.y = GetRandomValue(area.y + 25, area.y + area.w - 25);


    timer = 1.0f;
    explosionTimer = 0.5f;
    exploding = false;
}

void Bomb::update( const SafeArea& safeArea )
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
            respawn(safeArea);
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