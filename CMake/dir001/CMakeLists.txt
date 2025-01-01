cmake_minimum_required(VERSION 3.30)
# message("***********First command***********")
# cmake -G "MinGW Makefiles" -S ../ -B ./
project(mainExe)
# set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
add_executable(mainExe main.cpp)
# target_link_libraries(mainExe mainExe)