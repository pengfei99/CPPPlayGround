cmake_minimum_required(VERSION 3.14)
project(MyWxApp)

set(CMAKE_CXX_STANDARD 17)
# Set wxWidgets root if needed (for Windows builds)
set(wxWidgets_ROOT_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets")
set(wxWidgets_LIB_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets/lib/gcc_lib")

# enable unicode support
set(wxWidgets_USE_UNICODE ON)

# Find static build
set(wxWidgets_USE_STATIC ON)

# Find wxWidgets with desired components
find_package(wxWidgets REQUIRED COMPONENTS net gl media core base)

# Include wxWidgets use file
include(${wxWidgets_USE_FILE})

# Add definitions (optional redundancy)
add_definitions(-DUNICODE -D__UNICODE)

# Define target and link libraries
add_executable(MyWxApp 
    src/main.cpp
    app.rc
    )

target_include_directories(MyWxApp PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
