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

    for (const auto& entry : std::filesystem::directory_iterator("./lib")) {
        if (entry.is_regular_file() && (entry.path().filename().find("raylib") != std::string::npos)) {
            dl = std::make_unique<>(entry);
            break;
        }
    }
    EXPECT_NE(nullptr, dl);
}

TEST (DynamicLibrary, EntryPointCorrectRayLib) {
    IGraphicalLibrary *engine = nullptr;

    for (const auto& entry : std::filesystem::directory_iterator("./lib")) {
        if (entry.is_regular_file() && (entry.path().filename().find("raylib") != std::string::npos)) {
            auto dl = std::make_unique<LibDl::DynamicLibrary>(entry);
            auto fct = dl->getSym<IGraphicalLibrary * (*)(void)>("entryPointGraphicalLibrary");
            engine = fct();
            break;
        }
    }
    EXPECT_NE(nullptr, engine);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}