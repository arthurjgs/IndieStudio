//
// Created by sins on 4/2/21.
//

#include "../src/DynamicLibrary.hpp"
#include <gtest/gtest.h>

TEST (DynamicLibrary, DynamicLibraryError) {
    ASSERT_THROW(LibDl::DynamicLibrary("arthur"), LibDl::DynamicLibraryException);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}