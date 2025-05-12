cmake_minimum_required(VERSION 3.14)
project(SecuHub)

set(CMAKE_CXX_STANDARD 17)
# Set wxWidgets root if needed (for Windows builds)
set(wxWidgets_ROOT_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets")
set(wxWidgets_LIB_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets/lib/gcc_lib")
# set(wxWidgets_INCLUDE_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets-3.2.8/include")

# enable unicode support
set(wxWidgets_USE_UNICODE ON)

# Find static build
set(wxWidgets_USE_STATIC ON)

# Find wxWidgets with desired components
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include wxWidgets use file
include(${wxWidgets_USE_FILE})

# Add definitions (optional redundancy)
add_definitions(-DUNICODE -D__UNICODE)

# Define target and link libraries
add_executable(SecuHub 
    src/main.cpp
    include/bouclier_png.h
    include/casd_png.h
    include/server_png.h)

target_include_directories(SecuHub PRIVATE include)
target_link_libraries(SecuHub ${wxWidgets_LIBRARIES})
