#include "RayLib/Window.hpp"
#include "RayLib/InputKeyboard.hpp"
#include "RayLib/InputMouse.hpp"
#include "raylib.h"
#include "Game/SceneManager/SceneManager.hpp"
#include "Game/LoadingScreen/LoadingScreen.hpp"
#include "Game/TestScene/TestScene.hpp"
#include "Game/Player.hpp"

int main()
{
    RayLib::Window::getInstance();

    Bomberman::SceneManager engine;

    Bomberman::changeScene<Bomberman::TestScene>(engine);

    std::unique_ptr<Bomberman::Player> player = std::make_unique<Bomberman::Player>("Bomberman", Type::Vector<3>(0.0f, 0.0f, 0.0f) ,"assets/models/bomberman");
    Camera camera = { { 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    while (RayLib::Window::getInstance().isOpen()) {
        // if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(::KEY_A) == true)
        //     engine.newScene<Bomberman::TestScene>();
        // if (RayLib::Window::getInstance().getInputKeyboard().isKeyReleased(::KEY_E) == true)
        //     engine.unloadScene();
        engine.checkStack(); // check if stack has scene to render
        engine.update(RayLib::Window::getInstance().getElapsedTime());
        RayLib::Window::getInstance().draw(engine);
    }
    return 0;
}
