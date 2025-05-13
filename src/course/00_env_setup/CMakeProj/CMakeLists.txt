cmake_minimum_required(VERSION 3.14)
project(HelloCPP)

set(CMAKE_CXX_STANDARD 17)


# Add definitions (optional redundancy)
add_definitions(-DUNICODE -D__UNICODE)

# Define target and link libraries
add_executable(HelloCPP
    src/main.cpp)

target_include_directories(HelloCPP PRIVATE include)
target_link_libraries(HelloCPP ${wxWidgets_LIBRARIES})
