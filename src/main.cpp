#include "RayLib/Window.hpp"
#include "RayLib/InputKeyboard.hpp"
#include "RayLib/InputMouse.hpp"
#include "raylib.h"
#include "Game/SceneManager/SceneManager.hpp"
#include "Game/LoadingScreen/LoadingScreen.hpp"
#include "Game/TestScene/TestScene.hpp"
#include "Game/MainMenu/MainMenu.hpp"

int main()
{
    RayLib::Window::getInstance();

    Bomberman::SceneManager engine;

    //Bomberman::changeScene<Bomberman::TestScene>(engine);
    engine.newScene<Bomberman::Menu::MainMenu>();

    while (RayLib::Window::getInstance().isOpen()) {
        engine.checkStack(); // check if stack has scene to render
        engine.update(RayLib::Window::getInstance().getElapsedTime());
        RayLib::Window::getInstance().draw(engine);
    }
    return 0;
}
