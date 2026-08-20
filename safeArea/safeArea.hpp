#pragma once

#include <raylib.h>

class SafeArea {
    public:
        SafeArea();

        void update();
        void draw();

        Vector4 getAreaLivre() const;
    private:
        Rectangle safeArea;
};