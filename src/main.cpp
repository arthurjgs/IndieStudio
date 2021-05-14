#include "main.h"
#include "DynamicLibrary.hpp"
#include "IGraphicalLibrary.hpp"
#include <memory>

int main()
{
    IGraphicalLibrary *engine = nullptr;

    auto dl = std::make_unique<LibDl::DynamicLibrary>("indie_raylib.dll");
    auto fct = dl->getSym<IGraphicalLibrary * (*)(void)>("entryPointGraphicalLibrary");
    engine = fct();

    std::cout << engine->getElapsedTime() << std::endl;

    return 0;
}