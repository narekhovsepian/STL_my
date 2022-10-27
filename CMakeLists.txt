cmake_minimum_required(VERSION 3.10)

#set the project name
project(STL_my)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(stl_my STL_my/Source.cpp)


target_include_directories(stl_my PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


