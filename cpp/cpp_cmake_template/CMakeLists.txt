cmake_minimum_required(VERSION 3.12)

project(CMakeExampleProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_SOURCE_DIR}/build                    )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/release/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/debug/bin  )

if (MSVC)
   add_compile_options(/W4 /WX)
else()
   add_compile_options(-pedantic-errors -Wall -Wextra -Werror)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
