#include "RayLib/Window.hpp"
#include "RayLib/InputKeyboard.hpp"
#include "RayLib/InputMouse.hpp"
#include "raylib.h"
#include "Game/SceneManager/SceneManager.hpp"
#include "Game/LoadingScreen/LoadingScreen.hpp"
#include "Game/TestScene/TestScene.hpp"

int main()
{
    RayLib::Window::getInstance();

    Bomberman::SceneManager engine;

    engine.newScene<Bomberman::LoadingScreen>();

    while (RayLib::Window::getInstance().isOpen()) {
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(::KEY_A) == true)
            engine.newScene<Bomberman::TestScene>();
        if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(::KEY_E) == true)
            engine.unloadScene();
        engine.checkStack(); // check if stack has scene to render
        engine.update(RayLib::Window::getInstance().getElapsedTime());
        RayLib::Window::getInstance().draw(engine);
    }
    return 0;
}
