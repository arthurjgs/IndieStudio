//
// Created by sins on 4/2/21.
//

#include "../src/DynamicLibrary.hpp"
#include "../shared/IGraphicalLibrary.hpp"
#include <gtest/gtest.h>
#include <filesystem>

TEST (DynamicLibrary, DynamicLibraryError) {
    ASSERT_THROW(LibDl::DynamicLibrary("arthur"), LibDl::DynamicLibraryException);
}

TEST (DynamicLibrary, DynamicLibraryCorrectRayLib) {
    std::unique_ptr<LibDl::DynamicLibrary> dl = nullptr;

#if defined _WIN32 || defined __CYGWIN__
    dl = std::make_unique<LibDl::DynamicLibrary>("indie_raylib.dll");
#elif defined __APPLE__
    dl = std::make_unique<LibDl::DynamicLibrary>("./lib/indie_raylib.dylib");
#elif defined __linux__
    dl = std::make_unique<LibDl::DynamicLibrary>("./lib/indie_raylib.so");
#endif
    dl.reset();
    EXPECT_NE(nullptr, dl);
}

TEST (DynamicLibrary, EntryPointCorrectRayLib) {
    IGraphicalLibrary *engine = nullptr;

#if defined _WIN32 || defined __CYGWIN__
    auto dl = std::make_unique<LibDl::DynamicLibrary>("indie_raylib.dll");
#elif defined __APPLE__
    auto dl = std::make_unique<LibDl::DynamicLibrary>("./lib/indie_raylib.dylib");
#elif defined __linux__
    auto dl = std::make_unique<LibDl::DynamicLibrary>("./lib/indie_raylib.so");
#endif
    auto fct = dl->getSym<IGraphicalLibrary* (*)(void)>("entryPointGraphicalLibrary");
    engine = fct();

    std::cout << engine->getElapsedTime() << std::endl;
    dl.reset();
    EXPECT_NE(nullptr, engine);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}