cmake_minimum_required(VERSION 3.0)
project(Livestock management)
include_directories(include)
add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/app.cpp
)