cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE /home/vgreff/gh/oss/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")


project(HelloWorld)

add_subdirectory(src)

# # find_package(Boost 1.83 REQUIRED)
