#include "RayLib/Window.hpp"
#include "RayLib/InputKeyboard.hpp"
#include "RayLib/InputMouse.hpp"
#include "raylib.h"

int main()
{
    RayLib::Window::getInstance();
    while (RayLib::Window::getInstance().isOpen()) {
        if (RayLib::Window::getInstance().getInputGamepad().getGamepadButtonPressed() != -1)
            std::cout << RayLib::Window::getInstance().getInputGamepad().getGamepadButtonPressed() << std::endl;
        ::BeginDrawing();
        ::ClearBackground(::RAYWHITE);
        ::EndDrawing();
    }
    return 0;
}
