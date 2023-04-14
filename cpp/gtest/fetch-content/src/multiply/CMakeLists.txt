
add_library(multiply multiply.cpp)

target_include_directories(multiply PUBLIC include)

add_executable(vgmult main.cpp )
target_link_libraries(vgmult PRIVATE multiply)