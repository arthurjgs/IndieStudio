#include <Game/GameScene/GameScene.hpp>
#include "RayLib/Window.hpp"
#include "RayLib/InputKeyboard.hpp"
#include "RayLib/InputMouse.hpp"
#include "raylib.h"
#include "Game/SceneManager/SceneManager.hpp"
#include "Game/LoadingScreen/LoadingScreen.hpp"
#include "Game/TestScene/TestScene.hpp"
#include "players/Player.hpp"
#include "Game/MainMenu/MainMenu.hpp"
#include "Game/QuitGame/QuitGame.hpp"
#include "Game/Config.hpp"

int main()
{
    RayLib::Window::getInstance();
    Bomberman::Config::initialize();

    Bomberman::SceneManager engine;

    engine.newScene<Bomberman::Menu::MainMenu>();
    try {
        try {
            while (RayLib::Window::getInstance().isOpen()) {
                engine.checkStack(); // check if stack has scene to render
                engine.update(RayLib::Window::getInstance().getElapsedTime());
                RayLib::Window::getInstance().draw(engine);
            }    
        }
        catch(const Bomberman::QuitGame &e) {
            return (0);
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return 0;
}
