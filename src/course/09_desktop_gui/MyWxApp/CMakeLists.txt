cmake_minimum_required(VERSION 3.14)
project(MyWxApp)

set(CMAKE_CXX_STANDARD 17)
set(wxWidgets_ROOT_DIR "C:/wxWidgets")

# Tell wx-config where to find wxWidgets
set(wxWidgets_CONFIG_EXECUTABLE "")

# Find static build
set(wxWidgets_USE_STATIC ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

add_executable(MyWxApp main.cpp)
target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
