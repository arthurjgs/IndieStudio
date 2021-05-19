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

TEST (DynamicLibrary, EntryPointCorrectRayLib) {
    IGraphicalLibrary* engine = nullptr;
#if defined _WIN32 || defined __CYGWIN__
    for (auto p : std::filesystem::directory_iterator("./Release")) {
#else
    for (auto p : std::filesystem::directory_iterator("./lib")) {
#endif
        std::cout << p.path().string() << std::endl;
    	if (p.is_regular_file()) {
            auto fileStr = p.path().string();
#if defined _WIN32 || defined __CYGWIN__
            if (fileStr.find("raylib.dll") != std::string::npos) {
#else
            if (fileStr.find("raylib") != std::string::npos) {
#endif
                auto dl = std::make_unique<LibDl::DynamicLibrary>(fileStr);
                auto fct = dl->getSym<IGraphicalLibrary* (*)(void)>("entryPointGraphicalLibrary");
                engine = fct();
            }
        }
    }    

    EXPECT_NE(nullptr, engine);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}