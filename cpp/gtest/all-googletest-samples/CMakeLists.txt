cmake_minimum_required(VERSION 3.16)
project(MultiplyTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(thisproject_headerdir ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/1 ${PROJECT_SOURCE_DIR}/2 ${PROJECT_SOURCE_DIR}/3 ${PROJECT_SOURCE_DIR}/4 ${PROJECT_SOURCE_DIR}/5 ${PROJECT_SOURCE_DIR}/6 ${PROJECT_SOURCE_DIR}/7 ${PROJECT_SOURCE_DIR}/8 ${PROJECT_SOURCE_DIR}/9 ${PROJECT_SOURCE_DIR}/10 )

 include_directories(${thisproject_headerdir})

enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
    
    add_library(GTest::GTest INTERFACE IMPORTED)
    target_link_libraries(GTest::GTest INTERFACE gtest_main)
    
add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)
add_subdirectory(10)