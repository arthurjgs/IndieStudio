#include "RayLib/Window.hpp"

int main()
{
    RayLib::Window::getInstance();
    while (RayLib::Window::getInstance().isOpen()) {

    }
    return 0;
}