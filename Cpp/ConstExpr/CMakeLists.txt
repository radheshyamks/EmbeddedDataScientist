cmake_minimum_required(VERSION 3.30)
# cmake -G "MinGW Makefiles" -S ../ -B ./
message(${CMAKE_CURRENT_LIST_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_LIST_FILE})
project(constExpr)
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
add_executable(constExpr constExpr01.cpp ConstExprFun.cpp)