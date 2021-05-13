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

    for (const auto& entry : std::filesystem::directory_iterator("../lib")) {
        std::string filenameStr = entry.path().string();
        if (entry.is_regular_file() && (filenameStr.find("raylib") != std::string::npos)) {
            dl = std::make_unique<LibDl::DynamicLibrary>(filenameStr);
            break;
        }
    }
    EXPECT_NE(nullptr, dl);
}

TEST (DynamicLibrary, EntryPointCorrectRayLib) {
    IGraphicalLibrary *engine = nullptr;

    for (const auto& entry : std::filesystem::directory_iterator("../lib")) {
        std::string filenameStr = entry.path().string();
        if (entry.is_regular_file() && (filenameStr.find("raylib") != std::string::npos)) {
            auto dl = std::make_unique<LibDl::DynamicLibrary>(filenameStr);
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