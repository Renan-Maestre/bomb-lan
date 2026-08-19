#pragma once

#include <raylib.h>

class SafeArea {
    public:
        SafeArea();

        void update();
        void draw();
    private:
        Rectangle safeArea;
};