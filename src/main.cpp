#include "RayLib/Window.hpp"
#include "raylib.h"

int main()
{
    RayLib::Window::getInstance();
    while (RayLib::Window::getInstance().isOpen()) {
        ::BeginDrawing();
        ::ClearBackground(::RAYWHITE);
        ::EndDrawing();
    }
    return 0;
}
