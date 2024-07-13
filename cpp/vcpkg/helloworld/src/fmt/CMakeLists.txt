
find_package(fmt CONFIG REQUIRED)
# find_package(Boost 1.83 REQUIRED)

add_executable(HelloWorld helloworld.cpp)
target_link_libraries(HelloWorld PRIVATE fmt::fmt )
