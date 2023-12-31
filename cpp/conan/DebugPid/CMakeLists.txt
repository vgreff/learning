cmake_minimum_required (VERSION 3.8)

project(DebugPidApp CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(MyDebugPidLib MyDebugPid.cpp MyDebugPid.hpp)

# Link each target with other targets or add options, etc.


add_executable(debugPidApp main.cpp)
target_link_libraries(debugPidApp PRIVATE MyDebugPidLib ${CONAN_LIBS})

