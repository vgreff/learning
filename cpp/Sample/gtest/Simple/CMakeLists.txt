cmake_minimum_required(VERSION 3.16)

set(SampleNb 2)
set(SampleName sample${SampleNb})

project(${SampleName}Test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_library(${SampleName} ${SampleName}.cc)

target_include_directories(${SampleName} PUBLIC include)


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

add_executable(${SampleName}_test ${SampleName}_unittest.cc)

target_link_libraries(${SampleName}_test
 PRIVATE
  GTest::GTest
  ${SampleName})

add_test(${SampleName}_gtests ${SampleName}_test)
