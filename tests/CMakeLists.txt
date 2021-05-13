CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(unit_tests)
SET(CMAKE_CXX_STANDARD 17)

INCLUDE(GoogleTest)

ENABLE_TESTING()

ADD_EXECUTABLE(unit_tests
        google_test.cpp
        ../shared/IGraphicalLibrary.hpp
        ../src/DynamicLibrary.cpp
        ../src/DynamicLibrary.hpp
        ../src/DynamicLibraryException.cpp
        ../src/DynamicLibraryException.hpp)

target_link_libraries(unit_tests gtest_main)
target_link_libraries(unit_tests ${CMAKE_DL_LIBS})

gtest_discover_tests(unit_tests)
